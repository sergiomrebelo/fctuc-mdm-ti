const long RED = 11;
const long GREEN = 10;
const long BLUE = 9;

boolean vRed = LOW;

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {

  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
  /* while (Serial.available()) {
    char incomingByte = (char)Serial.read();
    if (incomingByte == 'R') {
      if (vRed == HIGH) {
        vRed = LOW;
      } else {
        vRed = HIGH;
      }
    }
  }*/


  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
}
