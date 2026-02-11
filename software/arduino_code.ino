/*
  Project: Centralized Monitoring System for Street Light Fault Detection
  Developed By: Tanmay Dhamane & Team

  Features:
  - Day/Night detection using LDR
  - Motion detection using PIR sensors
  - Smart dimming using PWM
  - Voltage monitoring
  - Current monitoring (ACS712)
  - Light status detection
*/

//////////////////// PIN DEFINITIONS ////////////////////

// LDR Pins
const int ldrMain = A10;     // Day/Night detection
const int ldrPins[10] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9};

// LED Pins
const int ledPins[6] = {3, 4, 5, 6, 7, 8};

// PIR Sensors
const int PIR_Left  = 10;
const int PIR_Right = 11;

// Voltage Sensor
#define VOLTAGE_PIN A12
float R1 = 30000.0;
float R2 = 7500.0;
float ref_voltage = 5.0;

// Current Sensor
#define CURRENT_PIN A11

//////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);

  pinMode(PIR_Left, INPUT);
  pinMode(PIR_Right, INPUT);

  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

//////////////////////////////////////////////////////////

void loop() {

  int dayNight = analogRead(ldrMain);

  if (dayNight < 175) {   // NIGHT CONDITION

    monitorVoltage();
    monitorCurrent();
    motionControl();
    checkLightStatus();

  } else {
    Serial.println("DAY TIME - LIGHTS OFF");
    lightsOff();
  }

  delay(1000);
}

//////////////////////////////////////////////////////////
// 🔆 MOTION CONTROL
//////////////////////////////////////////////////////////

void motionControl() {

  int leftMotion  = digitalRead(PIR_Left);
  int rightMotion = digitalRead(PIR_Right);

  if (leftMotion && rightMotion) {
    Serial.println("Motion on BOTH sides");
    fullIntensity();
  }
  else if (leftMotion) {
    Serial.println("Motion on LEFT side");
    fullLeft();
  }
  else if (rightMotion) {
    Serial.println("Motion on RIGHT side");
    fullRight();
  }
  else {
    Serial.println("No Motion - DIM mode");
    dimIntensity();
  }
}

//////////////////////////////////////////////////////////
// 💡 LIGHT MODES
//////////////////////////////////////////////////////////

void fullIntensity() {
  for (int i = 0; i < 6; i++) {
    analogWrite(ledPins[i], 255);
  }
}

void dimIntensity() {
  for (int i = 0; i < 6; i++) {
    analogWrite(ledPins[i], 95);
  }
}

void fullLeft() {
  for (int i = 0; i < 3; i++) {
    analogWrite(ledPins[i], 255);
  }
  for (int i = 3; i < 6; i++) {
    analogWrite(ledPins[i], 95);
  }
}

void fullRight() {
  for (int i = 0; i < 3; i++) {
    analogWrite(ledPins[i], 95);
  }
  for (int i = 3; i < 6; i++) {
    analogWrite(ledPins[i], 255);
  }
}

void lightsOff() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

//////////////////////////////////////////////////////////
// ⚡ VOLTAGE MONITORING
//////////////////////////////////////////////////////////

void monitorVoltage() {

  int adc_value = analogRead(VOLTAGE_PIN);
  float adc_voltage = (adc_value * ref_voltage) / 1024.0;
  float in_voltage = adc_voltage * (R1 + R2) / R2;

  if (in_voltage < 2.75) {
    Serial.print("LOW VOLTAGE: ");
    Serial.println(in_voltage);
  }
  else if (in_voltage > 3.40) {
    Serial.print("HIGH VOLTAGE: ");
    Serial.println(in_voltage);
  }
}

//////////////////////////////////////////////////////////
// 🔋 CURRENT MONITORING (ACS712)
//////////////////////////////////////////////////////////

void monitorCurrent() {

  float samples = 0;

  for (int i = 0; i < 150; i++) {
    samples += analogRead(CURRENT_PIN);
  }

  float avg = samples / 150.0;
  float voltage = avg * (5.0 / 1024.0);
  float current = (2.5 - voltage) / 0.066;

  if (current < -0.25) {
    Serial.print("LOW CURRENT: ");
    Serial.println(current);
  }
  else if (current > 0.02) {
    Serial.print("HIGH CURRENT: ");
    Serial.println(current);
  }
}

//////////////////////////////////////////////////////////
// 🌗 LIGHT STATUS CHECK
//////////////////////////////////////////////////////////

void checkLightStatus() {

  for (int i = 0; i < 10; i++) {

    int value = analogRead(ldrPins[i]);

    Serial.print("Light ");
    Serial.print(i + 1);

    if (value > 90) {
      Serial.println(" - ON");
    }
    else if (value > 50) {
      Serial.println(" - DIM");
    }
    else {
      Serial.println(" - OFF");
    }
  }
}
