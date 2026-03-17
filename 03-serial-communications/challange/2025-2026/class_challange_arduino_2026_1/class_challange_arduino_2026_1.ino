const long LED_R = 12;
const long LED_G = 4;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'R' || command == 'r') {
      digitalWrite(LED_R, HIGH);
    } else {
      digitalWrite(LED_R, LOW);
    }

    if (command == 'G' || command == 'g') {
      digitalWrite(LED_G, HIGH);
    } else {
      digitalWrite(LED_G, LOW);
    }
  }
}