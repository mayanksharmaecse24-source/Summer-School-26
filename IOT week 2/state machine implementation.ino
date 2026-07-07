const int coinButton = 2;
const int selectButton = 3;
const int cancelButton = 4;

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

const int IDLE = 0;
const int COIN_INSERTED = 1;
const int ITEM_SELECTED = 2;
const int DISPENSING = 3;

int currentState = IDLE;

void showState() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  if (currentState == COIN_INSERTED)
    digitalWrite(led1, HIGH);
  else if (currentState == ITEM_SELECTED)
    digitalWrite(led2, HIGH);
  else if (currentState == DISPENSING)
    digitalWrite(led3, HIGH);
}

void changeState(int newState) {
  currentState = newState;
  showState();

  Serial.print("State -> ");

  if (currentState == IDLE)
    Serial.println("IDLE");
  else if (currentState == COIN_INSERTED)
    Serial.println("COIN_INSERTED");
  else if (currentState == ITEM_SELECTED)
    Serial.println("ITEM_SELECTED");
  else if (currentState == DISPENSING)
    Serial.println("DISPENSING");
}

void setup() {
  pinMode(coinButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(cancelButton, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);

  showState();
  Serial.println("State -> IDLE");
}

void loop() {

  if (digitalRead(coinButton) == LOW && currentState == IDLE) {
    delay(200);
    changeState(COIN_INSERTED);
  }

  if (digitalRead(selectButton) == LOW && currentState == COIN_INSERTED) {
    delay(200);
    changeState(ITEM_SELECTED);

    delay(1000);

    changeState(DISPENSING);

    delay(2000);

    changeState(IDLE);
  }

  if (digitalRead(cancelButton) == LOW &&
      (currentState == COIN_INSERTED || currentState == ITEM_SELECTED)) {
    delay(200);
    changeState(IDLE);
  }
}
