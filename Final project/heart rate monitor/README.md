❤️ Heart Rate & SpO₂ Monitoring System (Simulation)

📌 Introduction
The proposed IoT-based Heart Rate and SpO₂ Monitoring System is designed as a learning prototype to monitor basic health parameters such as:
* ❤️Heart Rate (HR) in beats per minute (bpm)
* 🫁 Blood Oxygen Saturation (SpO₂) in percentage (%)

The system uses a "MAX30102 pulse oximeter sensor" connected through the "I2C communication protocol".
If the MAX30102 is unavailable in simulation, an LDR sensor can be used as an analog proxy to generate simulated readings.

> ⚠️Note: This project is only for learning sensor interfacing and IoT concepts. It is not a medical device and should not be used for diagnosis or treatment.

⚙️ Working of the System
The MAX30102 sensor collects pulse-related signals and provides data to the microcontroller.The controller processes these readings and calculates the simulated:
* Heart Rate
* SpO₂ level

The values are updated every 2 seconds and displayed on:
* 📟 LCD Display, or
* 💻 Serial Monitor

Example display:
❤️ HR: 78 bpm
🫁 SpO₂: 97%
Status: NORMAL

🔌 MAX30102 Sensor Integration
The MAX30102 communicates with the microcontroller using I2C, which requires mainly two communication lines:

| I2C Line | Purpose               |
| -------- | --------------------- |
| SDA      | Transfers sensor data |
| SCL      | Provides clock signal |

I2C is suitable because it requires fewer wires and allows efficient communication between the sensor and microcontroller.

If an LDR is used as a proxy sensor, its analog values are mapped into simulated Heart Rate and SpO₂ ranges.

📊 5-Reading Rolling Average

Sensor readings may contain noise or sudden fluctuations. To improve stability, the system implements a 5-reading rolling average.

For example, if five Heart Rate readings are:
"76, 80, 78, 82, 79"
Then:
Average HR = (76 + 80 + 78 + 82 + 79) / 5
Average HR = 79 bpm
Whenever a new reading arrives, the oldest reading is removed and the newest reading is added. This produces smoother and more reliable output.

🚨 Abnormal Reading Detection
The system continuously checks the smoothed readings against predefined thresholds:

| Parameter     | Condition     | Status    |
| ------------- | ------------- | --------- |
| ❤️ Heart Rate | 50–120 bpm    | 🟢 Normal |
| ❤️ Heart Rate | Below 50 bpm  | 🔴 Alert  |
| ❤️ Heart Rate | Above 120 bpm | 🔴 Alert  |
| 🫁 SpO₂       | 94% or above  | 🟢 Normal |
| 🫁 SpO₂       | Below 94%     | 🔴 Alert  |

🔴 LED Alert System
A Red LED is activated when any abnormal condition occurs:

* Heart Rate < 50 bpm
* Heart Rate > 120 bpm
* SpO₂ < 94%

Example:
🚨 HEALTH ALERT:
❤️ HR: 128 bpm
🫁 SpO₂: 92%
🔴 Status: ABNORMAL

If all values remain within the defined limits, the Red LED stays OFF.

💻 Display and Update Interval
The latest smoothed readings are displayed every 2 seconds.

Example Serial Monitor output:
"Time, Heart Rate, SpO2, Status"
'00:02, 78 bpm, 97%, NORMAL'
'00:04, 82 bpm, 96%, NORMAL'
'00:06, 125 bpm, 93%, ALERT'

This makes the monitoring process simple and easy to understand.

📁 Health Data Logging

All readings are recorded in CSV format for future analysis. The file is stored in the project repository as:

'/data/health_log.csv'

Example file content:

"Timestamp,Heart_Rate,SpO2,Status"
'00:02,78,97,NORMAL'
'00:04,82,96,NORMAL'
'00:06,125,93,ALERT'

The CSV file can later be analyzed using tools such as Excel, Python, or data visualization software.

🔄 System Flow
MAX30102 / LDR Sensor
⬇️
Read HR and SpO₂ Data
⬇️
Apply 5-Reading Rolling Average
⬇️
Update Display Every 2 Seconds
⬇️
Compare with Safety Thresholds
⬇️
Normal 🟢 / Abnormal 🔴
⬇️
Store Data in '/data/health_log.csv'

✅ Conclusion

The proposed Heart Rate and SpO₂ Monitoring System demonstrates important IoT and healthcare concepts such as sensor interfacing, I2C communication, signal smoothing, threshold-based alerts, periodic display updates, and CSV data logging.

The 5-reading rolling average reduces noisy fluctuations, while the Red LED alert immediately indicates abnormal readings. This makes the prototype useful for educational simulation and understanding wearable health-monitoring systems.

> ⚠️ This system is a **simulation prototype for learning purposes only** and is not intended for real medical diagnosis.
