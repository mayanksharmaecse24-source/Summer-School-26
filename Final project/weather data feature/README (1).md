# REST API – Weather Data Fetcher

## Project Description

This project uses an ESP32 to fetch real-time weather data from the OpenWeatherMap API using a REST API request. It also reads local temperature and humidity values from a DHT11 sensor.

The API temperature is compared with the local DHT11 temperature, and the difference is displayed on the Serial Monitor.

## Features

- Fetches real-time weather data from OpenWeatherMap API
- Reads local temperature using DHT11 sensor
- Reads local humidity using DHT11 sensor
- Displays city name
- Displays API temperature
- Displays local DHT11 temperature
- Displays API humidity
- Displays weather description
- Compares API temperature with local sensor temperature
- Calculates and displays temperature difference

## Components Required

- ESP32 DevKit V1
- DHT11 Temperature and Humidity Sensor
- Jumper Wires
- Breadboard
- WiFi Connection
- USB Cable

## Circuit Connections

| DHT11 Pin | ESP32 Pin |
|-----------|-----------|
| VCC       | 3.3V      |
| DATA      | GPIO 4    |
| GND       | GND       |

## Working

1. The DHT11 sensor measures local temperature and humidity.
2. ESP32 connects to the WiFi network.
3. ESP32 sends an HTTP GET request to the OpenWeatherMap API.
4. The API returns real-time weather data in JSON format.
5. ESP32 parses the JSON response using the ArduinoJson library.
6. API temperature is compared with the local DHT11 temperature.
7. The temperature difference is calculated.
8. All results are displayed on the Serial Monitor.

## System Diagram

The system consists of a DHT11 sensor, ESP32, WiFi connection, OpenWeatherMap API, and Serial Monitor.

![ESP32 REST API Weather Data Fetcher System Diagram](weather_data_fetcher_diagram.png)

## Libraries Required

- WiFi.h
- HTTPClient.h
- ArduinoJson.h
- DHT.h

## API Configuration

This project uses the OpenWeatherMap Current Weather API.

For security, the API key and WiFi credentials are stored separately in a `config.h` file.

Example:

```cpp
#ifndef CONFIG_H
#define CONFIG_H

#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"
#define OPENWEATHER_API_KEY "YOUR_API_KEY"

#endif
