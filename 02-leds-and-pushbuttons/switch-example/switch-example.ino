const int NO = 7; 

void setup() {
  pinMode(NO, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(NO) == HIGH) {
    Serial.println("Switch ON");
  } else {
    Serial.println("Switch OFF");
  }
  delay(100);
}