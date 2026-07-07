Q41. 🏠 Smart Home Air Quality Monitoring System

📌 Introduction
During winter in Milan, Europe, many families burn wood for heating.This may increase indoor smoke and harmful gases, creating health and safety risks.To solve this problem, an IoT-based Smart Home Air Quality Monitor can continuously check indoor conditions and immediately alert residents when air quality becomes unsafe.

⚙️ Working of the System
The system uses an MQ-2 gas sensor to detect smoke and harmful gas levels.
The sensor provides an analog value to the ESP32, which compares it with predefined thresholds:

| Air Quality  |   MQ-2 Value | LED Status | Alarm           |
| -----------  |-----------:  | ---------- | --------------- |
| 🟢 SAFE     |    Below 350 | Green      | Low / No Alarm  |
| 🟡 MODERATE |      350–599 | Yellow     | Medium Tone     |
| 🔴 DANGER   | 600 or above | Red        | High Alert Tone |

🎯 Sensor Calibration Logic
Before normal operation, the MQ-2 sensor is allowed to warm up in clean air.
Several readings are collected to determine a baseline value.
The warning and danger thresholds are then selected relative to this baseline.

For example:
Moderate Threshold = Baseline + 150
Danger Threshold = Baseline + 400

This makes detection more reliable than using random fixed values.

🌡️ Temperature and Humidity Monitoring
The DHT11 sensor continuously measures:
🌡️ Temperature
💧 Humidity

These readings help residents understand the complete indoor environment along with smoke levels.

🚨 Alarm Escalation
The system provides three levels of warning:
🟢 SAFE:Green LED glows and no urgent alarm is generated.
🟡 MODERATE:Yellow LED glows and the buzzer produces a medium warning tone. Residents are advised to check the fireplace.
🔴 DANGER:Red LED glows and a high-frequency urgent alarm is activated. Residents are advised to open windows and leave the room if necessary.

💻 Local Data Logging
All sensor readings are stored locally through the Serial Monitor in CSV format:
'Timestamp, MQ-2 Value, Temperature, Humidity, Severity Level'
Example:
"00:03, 420, 23.6°C, 49%, MODERATE"

This ensures that the system continues working even when the "internet or router is down".

📱 Bluetooth Mobile Alert
The ESP32 can send alerts directly to a smartphone using Bluetooth, without requiring internet access.
Example warning:

⚠️ WARNING
Moderate Smoke Detected
Gas = 430
Check Fireplace

Example danger alert:
-> DANGER!!
Smoke Level Critical
Gas = 765
Open Windows
Leave Room if Necessary

✅ Conclusion
The proposed system provides "24×7 indoor air-quality monitoring", local offline operation, visual LED indication, three-level buzzer alerts, CSV data logging, and Bluetooth mobile notifications. Therefore, it is a reliable and practical safety solution for homes using wood heating during winter.
