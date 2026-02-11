 🔌 Circuit Connections

 🌗 LDR Connections
- LDR1–LDR11 connected to Analog Pins A0–A10
- Configured using voltage divider circuit

 💡 LED Connections
- Left LEDs → Pins 3, 4, 5
- Right LEDs → Pins 6, 7, 8
- Controlled using PWM (analogWrite)

 🚶 PIR Sensors
- PIR1 → Digital Pin 10
- PIR2 → Digital Pin 11

 ⚡ Voltage Sensor
- Analog Output → A12
- Voltage Divider:
  - R1 = 30kΩ
  - R2 = 7.5kΩ

 🔋 Current Sensor (ACS712)
- Output → A11
- Measures load current

 📡 GPS Module
- TX → Arduino RX
- RX → Arduino TX
- VCC → 5V
- GND → GND

 📲 GSM Module
- TX → Arduino RX
- RX → Arduino TX
- Used to send SMS alerts with GPS location

---

 📌 Working Summary

1. LDR detects day/night.
2. PIR detects motion.
3. LEDs operate in dim mode normally.
4. Full intensity during motion.
5. Voltage & current monitored continuously.
6. Fault detected and location sent via GSM.
