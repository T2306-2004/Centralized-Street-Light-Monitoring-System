 🧠 System Algorithm

 Step 1: Start System

 Step 2: Read LDR11 Value
- If LDR value indicates daytime → Turn OFF lights
- If nighttime → Continue operation

 Step 3: Monitor Voltage
- If Voltage < Threshold → Display "Low Voltage"
- If Voltage > Threshold → Display "High Voltage"

 Step 4: Monitor Current
- If Current < Threshold → Display "Low Current"
- If Current > Threshold → Display "High Current"

 Step 5: Check PIR Sensors
- If Motion detected on Left → Left lights Full intensity
- If Motion detected on Right → Right lights Full intensity
- If Motion both sides → All lights Full intensity
- If No motion → Keep lights in Dim mode

 Step 6: Read All LDR Sensors
- Determine Light ON / DIM / OFF status
- Display result via Serial Monitor

 Step 7: Repeat Continuously
