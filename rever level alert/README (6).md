# River Water Level Alert (Flood Detection)

## Project Description

This project is a River Water Level Alert System designed using **Arduino UNO** in **Cirkit Designer**. It uses an HC-SR04 Ultrasonic Sensor to continuously measure the distance between the sensor and the water surface. As the water level rises, the measured distance decreases. Based on the measured distance, the system classifies the situation into Normal, Warning, or Critical and activates LEDs and a buzzer accordingly.

---

## Hardware Required

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- Green LED
- Yellow LED
- Red LED
- Active Buzzer
- 3 × 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Software Used

- Cirkit Designer
- Arduino IDE
- GitHub

---

## Circuit Connections

### HC-SR04
- VCC → 5V
- GND → GND
- TRIG → D9
- ECHO → D10

### LEDs
- Green LED → D2
- Yellow LED → D3
- Red LED → D4

### Buzzer
- Positive → D8
- Negative → GND

---

## Working Principle

1. The HC-SR04 sensor measures the distance from the sensor to the water surface.
2. Arduino calculates the distance in centimeters.
3. The measured distance is compared with predefined thresholds.
4. The system activates different LEDs and buzzer patterns depending on the water level.
5. The current distance and alert status are displayed on the Serial Monitor.

---

## Alert Levels

| Distance | Status | LED | Buzzer |
|----------|--------|-----|---------|
| >30 cm | NORMAL | Green | OFF |
| 15–30 cm | WARNING | Yellow | Slow Beep |
| <15 cm | CRITICAL | Red | Continuous Beep |

---

## Sample Serial Monitor Output

```
Distance : 42 cm
Status   : NORMAL

Distance : 25 cm
Status   : WARNING

Distance : 12 cm
Status   : CRITICAL
```

---

## Features

- Real-time water level monitoring
- Three-level flood alert system
- LED indication
- Buzzer alarm
- Serial Monitor logging
- Designed in Cirkit Designer

---

## Future Improvements

- Rolling average filter for more accurate readings.
- Wi-Fi or Bluetooth notifications.
- Cloud dashboard using ESP32 and Chart.js.
- SMS or Telegram alerts for emergency notifications.


## Author

**Name:** Mohit Kumar

**Course:** IoT Summer School 2026

**Platform:** Arduino UNO

**Circuit Design:** Cirkit Designer
