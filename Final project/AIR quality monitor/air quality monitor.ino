const int gasPin = A0;
const int tempPin = A1;

const int redLED = 8;
const int greenLED = 9;
const int blueLED = 10;

const int buzzer = 7;

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.println("Timestamp,Gas Value,Temperature(C),Severity");
}

void loop() {

  // Read gas sensor
  int gasValue = analogRead(gasPin);

  // Read TMP36
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  // Print CSV
  Serial.print(millis());
  Serial.print(",");
  Serial.print(gasValue);
  Serial.print(",");
  Serial.print(temperature, 1);
  Serial.print(",");

  // SAFE
  if (gasValue < 300) {

    Serial.println("SAFE");

    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);

    noTone(buzzer);
  }

  // MODERATE
  else if (gasValue >= 300 && gasValue < 600) {

    Serial.println("MODERATE");

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);   // Yellow
    digitalWrite(blueLED, LOW);

    tone(buzzer, 800);
    delay(200);
    noTone(buzzer);
    delay(300);
  }

  // DANGER
  else {

    Serial.println("DANGER");

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);

    tone(buzzer, 1500);
    delay(1000);
    noTone(buzzer);
  }

  delay(2000);
}
