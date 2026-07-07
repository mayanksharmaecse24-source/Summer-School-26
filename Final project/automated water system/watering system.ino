#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int soilPin = A0;
const int ldrPin = A1;

const int pumpLED = 8;
const int buttonPin = 7;

unsigned long lastWaterTime = 0;
unsigned long manualLockTime = 0;

const unsigned long lockDuration = 300000;   // 5 minutes

void setup() {

  Serial.begin(9600);

  lcd.begin(16,2);

  pinMode(pumpLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {

  int soil = analogRead(soilPin);
  int ldr = analogRead(ldrPin);

  int moisture = map(soil,1023,0,0,100);

  bool raining = (ldr < 400);

  String zone;

  if(moisture < 30)
    zone="DRY";
  else if(moisture<70)
    zone="OPTIMAL";
  else
    zone="WET";

  bool manualPressed = digitalRead(buttonPin)==LOW;

  // Manual Override
  if(manualPressed && millis()-manualLockTime>lockDuration){

      digitalWrite(pumpLED,HIGH);

      lastWaterTime=millis();

      manualLockTime=millis();

      Serial.println("Manual Override Activated");

      delay(3000);

      digitalWrite(pumpLED,LOW);
  }

  // Automatic Mode
  else{

      if(zone=="DRY" && !raining){

          digitalWrite(pumpLED,HIGH);

          lastWaterTime=millis();

      }

      else{

          digitalWrite(pumpLED,LOW);

      }

  }

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("M:");
  lcd.print(moisture);
  lcd.print("% ");

  lcd.print(zone);

  lcd.setCursor(0,1);

  if(digitalRead(pumpLED))
      lcd.print("Pump ON ");
  else
      lcd.print("Pump OFF");

  Serial.print("Moisture=");
  Serial.print(moisture);

  Serial.print("% Rain=");

  if(raining)
      Serial.print("YES");
  else
      Serial.print("NO");

  Serial.print(" Last=");
  Serial.println(lastWaterTime);

  delay(1000);
}
