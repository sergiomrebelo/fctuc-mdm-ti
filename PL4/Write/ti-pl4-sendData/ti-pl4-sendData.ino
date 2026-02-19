long xVar = 10;

void setup() {
  Serial.begin(9600);
  pinMode(INPUT, 9);
}

void loop() {
  Serial.print("Variable xVar is ");
  Serial.println(xVar);

  Serial.print("Digital pin 9: ");
  Serial.println(digitalRead(9));
  delay(2000);
}
