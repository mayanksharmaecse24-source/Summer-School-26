// Smart Greenhouse Controller
// Tinkercad Version (Without LCD)

const int tempPin = A1;
const int ldrPin = A0;

const int heaterLED = 8;
const int fanLED = 9;
const int growLED = 10;

void setup() {

  Serial.begin(9600);

  pinMode(heaterLED, OUTPUT);
  pinMode(fanLED, OUTPUT);
  pinMode(growLED, OUTPUT);
}

void loop() {

  // Read TMP36
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);

  float temperature = (voltage - 0.5) * 100.0;

  // Read LDR
  int lightValue = analogRead(ldrPin);

  // Heater & Fan Control
  if (temperature < 18) {

    digitalWrite(heaterLED, HIGH);
    digitalWrite(fanLED, LOW);

  }
  else if (temperature > 22) {

    digitalWrite(heaterLED, LOW);
    digitalWrite(fanLED, HIGH);

  }
  else {

    digitalWrite(heaterLED, LOW);
    digitalWrite(fanLED, LOW);

  }

  // Grow Light Control
  if (lightValue < 500) {

    digitalWrite(growLED, HIGH);

  }
  else {

    digitalWrite(growLED, LOW);

  }

  // Serial Monitor Output
  Serial.println("========== GREENHOUSE STATUS ==========");

  Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Light Value : ");
  Serial.println(lightValue);

  if (temperature < 18)
    Serial.println("Heater : ON");
  else
    Serial.println("Heater : OFF");

  if (temperature > 22)
    Serial.println("Fan : ON");
  else
    Serial.println("Fan : OFF");

  if (lightValue < 500)
    Serial.println("Grow Light : ON");
  else
    Serial.println("Grow Light : OFF");

  Serial.println("=======================================");
  Serial.println();

  delay(3000);
}
