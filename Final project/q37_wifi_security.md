# Q37: Wi-Fi Security for IoT Devices

IoT devices like ESP32 and ESP8266 are highly vulnerable to Wi-Fi based attacks  
due to weak security configurations and limited hardware resources.

Common attack vectors include WPA2 vulnerabilities, evil twin attacks, and insecure network configurations.

WPA2 networks can be attacked through weak password brute-force methods or handshake capture attacks.  
If the Wi-Fi password is weak, attackers can easily decrypt network traffic.

Another major threat is the Evil Twin attack, where an attacker creates a fake access point  
with the same SSID as a legitimate network. IoT devices may unknowingly connect to this fake network,  
allowing attackers to intercept sensitive data.

To secure ESP32 Wi-Fi connections, developers should follow best practices.

Using strong WPA2 or WPA3 passwords significantly reduces brute-force risks.  
WPA3 provides improved encryption and better protection against offline attacks.

Additionally, TLS encryption should be used for secure communication with cloud servers and APIs.  
Certificate pinning ensures the device connects only to trusted servers.

Hardcoding Wi-Fi credentials inside IoT firmware is extremely dangerous.  
If firmware is extracted, attackers can directly access the network.

Instead, secure provisioning methods like captive portals, encrypted flash storage,  
or mobile-based configuration apps should be used.

## References
- NIST IoT Security Guidelines (SP 800-183)
- OWASP IoT Security Guidance
