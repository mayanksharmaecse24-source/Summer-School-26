--Automated Plant Watering System--

Project Description:
This project is an IoT-based Automated Plant Watering System developed using Arduino UNO in Tinkercad. The system monitors soil moisture using a Soil Moisture Sensor and light intensity using a Photoresistor (LDR equivalent). A 16×2 LCD displays the soil moisture percentage, operating mode, and pump status. The pump is simulated using an LED. Manual watering is possible using a push button with a 5-minute lockout period.

Hardware Required:-
- Arduino UNO
- Soil Moisture Sensor
- Photoresistor (LDR Equivalent)
- 16×2 LCD Display
- 10kΩ Potentiometer (LCD Contrast)
- Push Button
- LED (Pump Simulation)
- 220Ω Resistor
- 10kΩ Resistor (Photoresistor Voltage Divider)
- Breadboard
- Jumper Wires

Circuit Connections
Soil Moisture Sensor-->
- VCC → 5V
- GND → GND
- Signal → A0
Photoresistor-->
- One pin → 5V
- Other pin → A1
- 10kΩ resistor from A1 → GND
Pump Simulation-->
- LED Anode → D8 through 220Ω resistor
- LED Cathode → GND
Push Button-->
- One terminal → D7
- Other terminal → GND
- INPUT_PULLUP is used in software

--LCD Connections--

| LCD Pin | Arduino Pin                    |
|---------|--------------------------------|
| RS      | D12                            |
| E       | D11                            |
| D4      | D5                             |
| D5      | D4                             |
| D6      | D3                             |
| D7      | D2                             |
| VSS     | GND                            |
| VDD     | 5V                             |
| RW      | GND                            |
| VO      | Middle pin of 10k Potentiometer|
| A       | 5V (through 220Ω resistor)     |
| K       | GND                            |

--Working Principle--
1. Reads soil moisture from the sensor.
2. Reads light intensity using the Photoresistor.
3. If soil moisture is below 35% and sufficient light is available, the pump (LED) turns ON automatically.
4. If the Photoresistor detects low light (rain/overcast simulation), watering is skipped.
5. Pressing the push button activates manual watering.
6. Manual watering is disabled for 5 minutes after activation using the 'millis()' function.
7. The LCD displays moisture percentage, operating mode, and pump status.

--Moisture Levels--

| Moisture (%) | Status |
|--------------|--------|
| Below 35%    | Dry    |
| 35%–70%      | Optimal|
| Above 70%    | Wet    |

--LCD Display Example--
M:28% ON
AUTO Clear

M:62% OFF
AUTO Rain

M:30% ON
MANUAL

--Sample Serial Monitor Output--
SMART PLANT WATERING SYSTEM

Soil Moisture : 28% (DRY)
Light Value   : 820
Weather       : Clear
Mode          : AUTO
Pump          : ON

Soil Moisture : 65% (OPTIMAL)
Light Value   : 180
Weather       : Rain/Cloudy
Mode          : AUTO
Pump          : OFF

--Features--
- Automatic irrigation
- Soil moisture monitoring
- Rain detection using Photoresistor
- Manual override button
- LCD status display
- Pump simulation using LED
- Non-blocking lockout using `millis()`

--Limitations--
This project is implemented in Tinkercad.Therefore:
- The water pump is simulated using an LED.
- The Photoresistor is used instead of an LDR module.
- Google Sheets logging and weather API integration are not supported in Tinkercad.
