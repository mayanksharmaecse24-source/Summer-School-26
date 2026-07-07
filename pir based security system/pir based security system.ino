#define PIR_PIN 2
#define POT_PIN A0

#define BUZZER 7

#define LED1 8
#define LED2 9
#define LED3 10

int startHour = 22;
int endHour = 6;

bool motionDetected = false;

void setup()
{
  pinMode(PIR_PIN, INPUT);

  pinMode(BUZZER, OUTPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  Serial.begin(9600);

  Serial.println("Security System Started");
  Serial.println("Command:");
  Serial.println("SET_HOURS 22 06");
}

void loop()
{

  readSerial();

  int sensitivity = analogRead(POT_PIN);

  int pir = digitalRead(PIR_PIN);

  int threshold = map(sensitivity,0,1023,0,1);

  if(pir > threshold)
  {
      motionEvent();
  }

  delay(200);

}

void motionEvent()
{

  Serial.println("---------------------------");
  Serial.print("Motion Detected at ");
  Serial.print(millis()/1000);
  Serial.println(" sec");

  Serial.println("Stage 1 : WARNING");

  tone(BUZZER,800);

  flashLEDs();

  delay(2000);

  Serial.println("Stage 2 : ALARM");

  tone(BUZZER,1500);

  flashLEDsFast();

  delay(2000);

  Serial.println("Stage 3 : URGENT");

  tone(BUZZER,2500);

  flashLEDsVeryFast();

  delay(3000);

  noTone(BUZZER);

  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);

  Serial.println("---------------------------");

}

void flashLEDs()
{

  digitalWrite(LED1,HIGH);
  delay(200);
  digitalWrite(LED1,LOW);

  digitalWrite(LED2,HIGH);
  delay(200);
  digitalWrite(LED2,LOW);

  digitalWrite(LED3,HIGH);
  delay(200);
  digitalWrite(LED3,LOW);

}

void flashLEDsFast()
{

  for(int i=0;i<3;i++)
  {

    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);

    delay(100);

    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);

    delay(100);

    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);

    delay(100);

    digitalWrite(LED3,LOW);

  }

}

void flashLEDsVeryFast()
{

  for(int i=0;i<8;i++)
  {

    digitalWrite(LED1,!digitalRead(LED1));
    digitalWrite(LED2,!digitalRead(LED2));
    digitalWrite(LED3,!digitalRead(LED3));

    delay(60);

  }

}

void readSerial()
{

  if(Serial.available())
  {

    String cmd = Serial.readStringUntil('\n');

    cmd.trim();

    if(cmd.startsWith("SET_HOURS"))
    {

      int space1 = cmd.indexOf(' ');
      int space2 = cmd.lastIndexOf(' ');

      startHour = cmd.substring(space1+1,space2).toInt();
      endHour = cmd.substring(space2+1).toInt();

      Serial.print("Shop Hours Updated : ");

      Serial.print(startHour);

      Serial.print(" to ");

      Serial.println(endHour);

    }

  }

}
