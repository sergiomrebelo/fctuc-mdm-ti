void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    if (str.equalsIgnoreCase("L")) {
      digitalWrite(LED_BUILTIN, LOW);
    } else if (str.equalsIgnoreCase("H")) {
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
}
