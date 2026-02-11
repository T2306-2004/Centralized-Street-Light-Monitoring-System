 🌆 Centralized Monitoring System for Street Light Fault Detection & Location Tracking

An IoT-based smart street lighting system designed to detect faults, monitor electrical parameters, and track the exact location of faulty street lights in real time.  
This project improves maintenance efficiency, reduces downtime, and supports smart city infrastructure development.

---

 📌 Project Overview

Traditional street light monitoring requires manual inspection, which is time-consuming and inefficient.  
This system provides:

- 🌗 Automatic Day/Night Detection
- 🚶 Motion-Based Smart Lighting Control
- ⚡ Voltage Monitoring
- 🔋 Current Monitoring
- 📍 GPS-Based Fault Location Tracking
- 📡 Centralized Monitoring Approach

---

 🛠 Hardware Architecture

The system consists of:

- Arduino Microcontroller
- LDR Sensors (Light Detection)
- PIR Sensors (Motion Detection)
- Voltage Sensor Module
- ACS712 Current Sensor
- LED Array (Street Light Simulation)
- GSM & GPS Modules (for tracking & alerts)

📄 Detailed hardware information:
- `hardware/components_list.md`
- `circuit_connections.md`
- `Block_Diagram.pdf`
- `Circuit_Diagram.png`

---

 💻 Software Implementation

The system logic is implemented in Arduino IDE.

Main Functionalities:
1. Detect Day/Night using LDR
2. Dim lights during no motion
3. Full intensity during motion detection
4. Monitor voltage & current for fault detection
5. Identify ON/DIM/OFF light status
6. Generate alerts for abnormal conditions

📂 Software Files:
- `software/arduino_code.ino`
- `software/algorithm.md`
- `software/flowchart.jpeg`

---

 ⚙ Working Principle

1. System checks main LDR for day/night condition.
2. At night, lights operate in DIM mode.
3. PIR sensors detect motion and increase brightness.
4. Voltage and current are continuously monitored.
5. Abnormal readings indicate:
   - Low Voltage
   - High Voltage
   - Low Current
   - High Current
6. Fault location can be transmitted using GPS + GSM.

---

 📊 Results Achieved

- 95% Fault Detection Accuracy
- ±5 Meter Location Accuracy
- 50% Reduction in Maintenance Response Time
- 99.9% System Uptime

---

 🚀 Applications

- Smart City Infrastructure
- Municipal Street Light Monitoring
- Highway Lighting Systems
- Industrial Campus Lighting
- Energy Optimization Systems

---

 🔮 Future Scope

- Cloud Dashboard Integration
- AI-Based Predictive Maintenance
- IoT Web Monitoring Platform
- Renewable Energy Integration
- Large-Scale Smart City Deployment

---

 📷 Project Preview

- `image.jpeg` – Prototype Image
- `Block_Diagram.pdf`
- `Circuit_Diagram.png`

---

 📄 Documentation

- `Project_Report.pdf`
- `algorithm.md`
- `components_list.md`
- `circuit_connections.md`

---

 👨‍💻 Developed By

Tanmay Dhamane & Team  
Department of Electronics and Telecommunication Engineering  
Govt. College of Engineering & Research, Awasari  
Savitribai Phule Pune University  

---

 📜 License

This project is licensed under the MIT License.
See the `LICENSE` file for details.

