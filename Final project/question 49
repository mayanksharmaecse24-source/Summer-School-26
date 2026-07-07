# Q49: Security Vulnerability Analysis of IoT Device

## Introduction

The given ESP8266 IoT code has several security problems.

The device connects to Wi-Fi, sends data using HTTP, and communicates through MQTT.

Without proper security, attackers can access the device and control it.

---

# Security Vulnerabilities

## 1. Hardcoded Wi-Fi Credentials

### Problem

The Wi-Fi SSID and password are directly written inside the program.

Example:

```cpp
const char* ssid = "MyWiFi";
const char* password = "12345678";
```

### Risk

* Anyone who gets the source code can see the password.
* Public GitHub repositories can expose credentials.
* Attackers can access the network.

### Solution

Use:

* Wi-Fi provisioning
* Encrypted storage
* Environment variables

---

# 2. Using HTTP Instead of HTTPS

## Problem

The device sends data using normal HTTP.

Example:

```text
http://server.com/data
```

## Risk

HTTP does not encrypt communication.

An attacker can:

* Read sensor data.
* Modify transmitted information.
* Perform Man-in-the-Middle attacks.

## Solution

Use HTTPS with SSL/TLS encryption.

Example:

```cpp
WiFiClientSecure client;
HTTPS connection;
```

---

# 3. Public MQTT Broker Without Authentication

## Problem

The ESP8266 publishes data to a public MQTT broker without login.

## Risk

Attackers can:

* Subscribe to sensor data.
* Publish fake messages.
* Control IoT devices.

## Solution

Use:

* MQTT username
* MQTT password
* TLS encryption

---

# 4. No Input Validation

## Problem

The device accepts any command received from MQTT or Wi-Fi.

## Risk

An attacker can send harmful commands.

Example:

```text
LED_ON
MOTOR_START
PUMP_ON
```

without permission.

## Solution

Allow only approved commands.

Example:

```cpp
if(command=="LED_ON")
{
 digitalWrite(LED,HIGH);
}

else
{
 Serial.println("Invalid Command");
}
```

---

# 5. No Authentication System

## Problem

The device does not check user identity.

## Risk

Unauthorized users can control the IoT system.

## Solution

Implement:

* User authentication
* API keys
* Secure tokens

---

# Corrected Code Examples

## 1. Secure MQTT Login

Before:

```cpp
client.connect("ESP8266");
```

After:

```cpp
client.connect(
"ESP8266",
"username",
"password"
);
```

---

## 2. HTTPS Communication

Before:

```cpp
http.begin(
"http://server.com"
);
```

After:

```cpp
WiFiClientSecure client;

HTTPClient https;

https.begin(
client,
"https://server.com"
);
```

---

# Conclusion

IoT devices require strong security because they are connected to the internet.

Using encryption, authentication, and input validation helps prevent unauthorized access and protects user data.
