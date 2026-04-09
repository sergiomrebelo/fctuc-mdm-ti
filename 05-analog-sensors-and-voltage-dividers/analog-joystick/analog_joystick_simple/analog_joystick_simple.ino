const int BT_X = A0;
const int BT_Y = A1;
int ellapsed;

void setup() {
  Serial.begin(9600);
  ellapsed = millis();
}

void loop() {
  if (millis() - ellapsed > 100) {
    int x = analogRead(BT_X);
    int y = analogRead(BT_Y);

    Serial.println("X:"+String(x));
    Serial.println("Y"+String(y));

    ellapsed = millis();
  }
}
