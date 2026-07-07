/*
  Q47 - Heart Rate & SpO2 Monitor (Simulation)
  Board: ESP32 DevKit V1
  Sensor: LDR used as proxy sensor

  Features:
  - Simulated Heart Rate and SpO2
  - 5-reading rolling average
  - Update every 2 seconds
  - Red LED abnormal alert
  - CSV-style Serial Monitor output

  NOTE:
  Educational simulation only.
  Not a medical device.
*/

// ---------------- PIN DEFINITIONS ----------------
#define LDR_PIN 34
#define RED_LED 2

// ---------------- ROLLING AVERAGE ----------------
const int WINDOW_SIZE = 5;

float hrReadings[WINDOW_SIZE] = {0, 0, 0, 0, 0};
float spo2Readings[WINDOW_SIZE] = {0, 0, 0, 0, 0};

int currentIndex = 0;
int readingCount = 0;

// ---------------- TIMING ----------------
unsigned long previousMillis = 0;
const unsigned long UPDATE_INTERVAL = 2000;

// Function to calculate average
float calculateAverage(float values[], int count) {
  float sum = 0;

  for (int i = 0; i < count; i++) {
    sum += values[i];
  }

  return sum / count;
}

// Function to create timestamp
String getTimestamp() {
  unsigned long totalSeconds = millis() / 1000;

  int minutes = totalSeconds / 60;
  int seconds = totalSeconds % 60;

  char timeBuffer[10];
  sprintf(timeBuffer, "%02d:%02d", minutes, seconds);

  return String(timeBuffer);
}

void setup() {

  Serial.begin(115200);

  pinMode(LDR_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(RED_LED, LOW);

  Serial.println("====================================");
  Serial.println(" Heart Rate & SpO2 Monitor");
  Serial.println(" Educational Simulation Only");
  Serial.println("====================================");

  // CSV Header
  Serial.println(
    "Timestamp,Raw_LDR,Heart_Rate,SpO2,Avg_HR,Avg_SpO2,Status"
  );
}

void loop() {

  unsigned long currentMillis = millis();

  // Update readings every 2 seconds
  if (currentMillis - previousMillis >= UPDATE_INTERVAL) {

    previousMillis = currentMillis;

    // Read LDR analog value
    int ldrValue = analogRead(LDR_PIN);

    /*
      Map LDR reading into simulated health values.

      ESP32 ADC Range:
      0 to 4095

      Simulated Heart Rate:
      45 to 130 bpm

      Simulated SpO2:
      90 to 100 %
    */

    float heartRate = map(
      ldrValue,
      0,
      4095,
      45,
      130
    );

    float spo2 = map(
      ldrValue,
      0,
      4095,
      90,
      100
    );

    // Add small random noise for realistic simulation
    heartRate += random(-3, 4);
    spo2 += random(-1, 2);

    // Limit values to valid simulation range
    heartRate = constrain(heartRate, 40, 140);
    spo2 = constrain(spo2, 85, 100);

    // Store current reading
    hrReadings[currentIndex] = heartRate;
    spo2Readings[currentIndex] = spo2;

    // Move circular buffer index
    currentIndex++;

    if (currentIndex >= WINDOW_SIZE) {
      currentIndex = 0;
    }

    // Increase count until 5 readings
    if (readingCount < WINDOW_SIZE) {
      readingCount++;
    }

    // Calculate rolling averages
    float avgHR = calculateAverage(
      hrReadings,
      readingCount
    );

    float avgSpO2 = calculateAverage(
      spo2Readings,
      readingCount
    );

    // ---------------- ALERT LOGIC ----------------

    bool abnormal = false;
    String status;

    if (
      avgHR < 50 ||
      avgHR > 120 ||
      avgSpO2 < 94
    ) {
      abnormal = true;
      status = "ALERT";
    }
    else {
      abnormal = false;
      status = "NORMAL";
    }

    // Control Red LED
    if (abnormal) {
      digitalWrite(RED_LED, HIGH);
    }
    else {
      digitalWrite(RED_LED, LOW);
    }

    // ---------------- CSV OUTPUT ----------------

    Serial.print(getTimestamp());
    Serial.print(",");

    Serial.print(ldrValue);
    Serial.print(",");

    Serial.print(heartRate, 1);
    Serial.print(",");

    Serial.print(spo2, 1);
    Serial.print(",");

    Serial.print(avgHR, 1);
    Serial.print(",");

    Serial.print(avgSpO2, 1);
    Serial.print(",");

    Serial.println(status);

    // ---------------- HUMAN READABLE ALERT ----------------

    if (abnormal) {

      Serial.println("🚨 HEALTH ALERT!");

      if (avgHR < 50) {
        Serial.println("Heart Rate Too Low!");
      }

      if (avgHR > 120) {
        Serial.println("Heart Rate Too High!");
      }

      if (avgSpO2 < 94) {
        Serial.println("SpO2 Level Too Low!");
      }

      Serial.println("----------------------------");
    }
  }
}
