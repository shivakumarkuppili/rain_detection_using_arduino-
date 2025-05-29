#define RAIN_SENSOR_DIGITAL_PIN 5  // Digital output pin from rain sensor
#define BUZZER_PIN 18              // Buzzer connected to digital pin

void setup() {
  Serial.begin(115200);
  pinMode(RAIN_SENSOR_DIGITAL_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Rain Detection System (Digital Sensor + Buzzer) Initialized");
}

void loop() {
  int rainDetected = digitalRead(RAIN_SENSOR_DIGITAL_PIN);

  if (rainDetected == LOW) { // LOW usually means rain detected
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Rain Detected! Buzzer ON");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("No Rain. Buzzer OFF");
  }

  delay(500); // Check every half second
}
