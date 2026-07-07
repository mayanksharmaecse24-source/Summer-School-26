# Smart Greenhouse Controller

## Description

This Smart Greenhouse Controller monitors greenhouse temperature and light conditions. A TMP36 sensor measures temperature while a Photoresistor detects ambient light. Three LEDs simulate a heater, ventilation fan and grow light. A 16×2 LCD displays the current temperature and system status.

## Components

- Arduino UNO
- TMP36 Temperature Sensor
- Photoresistor
- 3 LEDs
- Breadboard
- Jumper Wires

## Working

- Temperature below 18°C → Heater ON
- Temperature above 22°C → Fan ON
- Temperature between 18°C and 22°C → Normal
- Low light → Grow Light ON

- Sensor data is displayed on the Serial Monitor

## Features

- Automatic climate control
- Temperature monitoring
- Light monitoring
- Heater/Fan control
- Grow light control

## Note

This project is implemented in Tinkercad using TMP36 instead of DHT11 because DHT11 is not available in the simulation used for this assignment.

## Author

Mohit Kumar
IoT Summer School 2026
