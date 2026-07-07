# Smart Door Lock with OTP System (ESP32)

## Overview

This repository contains the firmware for an ESP32-based Smart Door Lock that uses a two-factor authentication method for university hostel entry. The system requires a static 4-digit Student ID followed by a dynamically generated 6-digit One-Time Password (OTP).

To simulate wireless delivery, the OTP is transmitted via the Serial Monitor (which can be easily adapted to a Bluetooth Serial module). A strict 30-second, non-blocking countdown timer secures the input window. Actuation is simulated using a micro servo motor.

## Features

* **Two-Factor Authentication:** Requires both a 4-digit ID and a dynamic 6-digit OTP.
* **Serial OTP Delivery:** Generates a 6-digit OTP and transmits it to the Serial Monitor (115200 baud).
* **Live Masked Display:** Uses a 16x2 I2C LCD to prompt the user and masks keypad inputs with asterisks (`*`) for security.
* **Non-Blocking 30s Timeout:** Utilizes `millis()` to enforce a 30-second window for OTP entry without freezing the system loop.
* **Hardware Actuation:** Uses an SG90 Servo motor to simulate a door lock (0° for locked, 90° for unlocked).
* **Access Logging:** Outputs detailed success, failure, and timeout logs to the Serial Monitor.

## Hardware Requirements

* **Microcontroller:** ESP32 Development Board
* **Display:** 16x2 LCD with I2C Backpack (Address `0x27` or `0x3F`)
* **Input:** 4x4 Membrane Keypad
* **Actuator:** SG90 Micro Servo Motor
* **Power:** 5V/3.3V Power supply, jumper wires, breadboard

## Pin Wiring & Configuration

### 4x4 Keypad

| Keypad Pin | ESP32 GPIO |
| --- | --- |
| Row 1 | GPIO 13 |
| Row 2 | GPIO 12 |
| Row 3 | GPIO 14 |
| Row 4 | GPIO 27 |
| Col 1 | GPIO 26 |
| Col 2 | GPIO 25 |
| Col 3 | GPIO 33 |
| Col 4 | GPIO 32 |

### 16x2 I2C LCD

| LCD Pin | ESP32 Pin |
| --- | --- |
| VCC | VIN (5V) / 3.3V |
| GND | GND |
| SDA | Default SDA (GPIO 21) |
| SCL | Default SCL (GPIO 22) |

### Servo Motor

| Servo Wire | ESP32 Pin |
| --- | --- |
| Signal (Orange/Yellow) | GPIO 18 |
| VCC (Red) | VIN (5V) |
| GND (Brown/Black) | GND |

## Software Dependencies

Ensure the following libraries are installed in your Arduino IDE Library Manager:

* **`LiquidCrystal_I2C`** by Frank de Brabander
* **`Keypad`** by Mark Stanley, Alexander Brevig
* **`ESP32Servo`** by Kevin Harrington, John K. Bennett

## Usage & System Workflow

1. **Boot Up:** The system initializes, the servo locks at 0°, and the LCD displays the "System Start" sequence.
2. **Enter ID:** The LCD prompts for a 4-digit ID. Enter any 4 digits on the keypad. Inputs are masked as `*`.
3. **OTP Generation:** Upon receiving 4 digits, the system generates a 6-digit OTP and prints it to the Serial Monitor (representing the student's phone).
4. **Enter OTP:** A 30-second timer begins. The user must enter the exact 6 digits seen on the Serial Monitor.
5. **Validation:**
* **Success:** If correct, the LCD displays "ACCESS GRANTED", the servo sweeps to 90° for 3 seconds, and a success log is generated. The system then relocks.
* **Failure:** If incorrect digits are entered, the system denies access, resets immediately, and logs the failure.
* **Timeout:** If 30 seconds pass before 6 digits are entered, the LCD displays "OTP Expired", access is denied, and the system resets
