# PIR-Based Security Camera Trigger

## Problem Statement

A small shop in Rohtak, Haryana requires a low-cost security alert system. The system detects motion after shop hours and activates an alarm with different alert levels. It also flashes LEDs, logs motion events, and is designed to support Telegram notifications when deployed on an ESP32. This project demonstrates the core functionality using Arduino Uno in Tinkercad.

---

## Objectives

- Detect motion using a PIR sensor.
- Adjust detection sensitivity using a potentiometer.
- Activate a 3-stage buzzer alarm.
- Flash LEDs sequentially during an alert.
- Configure shop hours through the Serial Monitor.
- Log all motion events with timestamps.
- Demonstrate a low-cost security solution.

---

## Hardware Required

- Arduino Uno
- PIR Motion Sensor
- Potentiometer (10kΩ)
- Piezo Buzzer
- 3 LEDs
- 3 × 220Ω Resistors
- Breadboard
- Jumper Wires
- USB Cable

---

## Software Used

- Arduino IDE
- Tinkercad

---

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| PIR OUT | D2 |
| PIR VCC | 5V |
| PIR GND | GND |
| Potentiometer Middle | A0 |
| Potentiometer Left | 5V |
| Potentiometer Right | GND |
| Buzzer | D7 |
| LED 1 | D8 |
| LED 2 | D9 |
| LED 3 | D10 |

---

## Features

- Motion detection using PIR sensor
- Adjustable sensitivity using potentiometer
- Three-stage alarm escalation
- Sequential LED flashing
- Serial Monitor event logging
- Shop hours configuration using Serial commands
- Tinkercad-compatible implementation

---

## Alarm Levels

### Stage 1 – Warning
- Low-frequency buzzer
- Slow LED sequence

### Stage 2 – Alarm
- Medium-frequency buzzer
- Fast LED flashing

### Stage 3 – Urgent
- High-frequency buzzer
- Very fast LED flashing

---

## Serial Commands

Set shop hours:

```
SET_HOURS 22 06
```

Example Output:

```
Shop Hours Updated : 22 to 06
```

---

## Serial Monitor Output

```
Security System Started

Motion Detected at 15 sec

Stage 1 : WARNING

Stage 2 : ALARM

Stage 3 : URGENT
```

---

## Working

1. Upload the Arduino code.
2. Open the Serial Monitor.
3. Enter:

```
SET_HOURS 22 06
```

4. Move your hand in front of the PIR sensor.
5. Observe:
   - Motion detection
   - LEDs flashing
   - Buzzer alarm
   - Event logs on Serial Monitor

---

## Limitations

Tinkercad does not support:
- ESP32 Wi-Fi
- Telegram Bot API
- Internet connectivity

Therefore, Telegram notifications are represented through Serial Monitor messages in this simulation.

---

## Future Improvements

- ESP32 implementation
- Telegram Bot notifications
- Camera integration
- Cloud event logging
- SD card storage
- Mobile application
- Email notifications



## Author

Mohit Kumar

---

## License

This project is developed for educational purposes as part of an IoT assignment.
