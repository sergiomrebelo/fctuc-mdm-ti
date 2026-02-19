const long PIN_RED = 3, PIN_GREEN = 4;
boolean redState = LOW, greenState = LOW;
void setup() {
  Serial.begin(3000);

  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    if (str.equalsIgnoreCase("R")) {
        redState = !redState;
    } else if (str.equalsIgnoreCase("G")) {
      greenState = !greenState;
    }
  }
  
  digitalWrite(PIN_RED, redState);
  digitalWrite(PIN_GREEN, greenState);
}
