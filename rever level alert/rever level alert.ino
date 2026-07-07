#define TRIG_PIN 5
#define ECHO_PIN 18

#define GREEN_LED 2
#define YELLOW_LED 4
#define RED_LED 15

#define BUZZER 13

float readings[10];
int index = 0;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  // Initialize array
  for (int i = 0; i < 10; i++) {
    readings[i] = 40;
  }
}

float getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.0343 / 2;

  return distance;
}

void loop() {

  float distance = getDistance();

  readings[index] = distance;

  index++;

  if (index >= 10)
    index = 0;

  // Rolling Average
  float average = 0;

  for (int i = 0; i < 10; i++) {
    average += readings[i];
  }

  average = average / 10;

  Serial.print("Average Distance = ");
  Serial.print(average);
  Serial.println(" cm");

  // Turn everything OFF first
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  noTone(BUZZER);

  // NORMAL
  if (average > 30) {

    digitalWrite(GREEN_LED, HIGH);

    Serial.println("NORMAL");

  }

  // WARNING
  else if (average >= 15 && average <= 30) {

    digitalWrite(YELLOW_LED, HIGH);

    tone(BUZZER, 1000);
    delay(200);
    noTone(BUZZER);

    Serial.println("WARNING");

  }

  // CRITICAL
  else {

    digitalWrite(RED_LED, HIGH);

    tone(BUZZER, 2000);

    Serial.println("CRITICAL");

  }

  delay(500);
}
