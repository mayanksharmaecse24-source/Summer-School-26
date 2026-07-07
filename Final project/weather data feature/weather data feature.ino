#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include "config.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Change city if required
const char* city = "Mathura";
const char* countryCode = "IN";

void setup() {
  Serial.begin(115200);
  dht.begin();

  Serial.println("Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");

  fetchWeatherData();
}

void loop() {
  // Fetch weather every 60 seconds
  delay(60000);
  fetchWeatherData();
}

void fetchWeatherData() {

  // Read local DHT11 sensor values
  float localTemp = dht.readTemperature();
  float localHumidity = dht.readHumidity();

  if (isnan(localTemp) || isnan(localHumidity)) {
    Serial.println("Failed to read from DHT11!");
    return;
  }

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    // OpenWeatherMap API URL
    String url =
      "http://api.openweathermap.org/data/2.5/weather?q=" +
      String(city) + "," +
      String(countryCode) +
      "&appid=" +
      String(OPENWEATHER_API_KEY) +
      "&units=metric";

    Serial.println();
    Serial.println("Fetching weather data...");

    http.begin(url);

    int httpResponseCode = http.GET();

    if (httpResponseCode == 200) {

      String payload = http.getString();

      // Parse JSON response
      JsonDocument doc;

      DeserializationError error =
        deserializeJson(doc, payload);

      if (error) {
        Serial.print("JSON parsing failed: ");
        Serial.println(error.c_str());
        http.end();
        return;
      }

      // Extract API values
      String cityName = doc["name"].as<String>();
      float apiTemp = doc["main"]["temp"].as<float>();
      float apiHumidity = doc["main"]["humidity"].as<float>();

      String weatherDescription =
        doc["weather"][0]["description"].as<String>();

      // Calculate temperature difference
      float tempDifference = localTemp - apiTemp;

      // Display results
      Serial.println("================================");
      Serial.println("       WEATHER DATA REPORT");
      Serial.println("================================");

      Serial.print("City Name: ");
      Serial.println(cityName);

      Serial.print("API Temperature: ");
      Serial.print(apiTemp);
      Serial.println(" C");

      Serial.print("DHT11 Local Temperature: ");
      Serial.print(localTemp);
      Serial.println(" C");

      Serial.print("API Humidity: ");
      Serial.print(apiHumidity);
      Serial.println(" %");

      Serial.print("DHT11 Local Humidity: ");
      Serial.print(localHumidity);
      Serial.println(" %");

      Serial.print("Weather Description: ");
      Serial.println(weatherDescription);

      Serial.print("Temperature Difference: ");
      Serial.print(tempDifference);
      Serial.println(" C");

      Serial.println("================================");
    }
    else {
      Serial.print("HTTP Error Code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
  else {
    Serial.println("WiFi disconnected!");
  }
}
