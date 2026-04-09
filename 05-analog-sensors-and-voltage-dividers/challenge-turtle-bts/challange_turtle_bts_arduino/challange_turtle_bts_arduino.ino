const int BT_A = 6;
const int BT_B = 7;
int ellapsed;

void setup() {
  pinMode(BT_A, INPUT_PULLUP);
  pinMode(BT_B, INPUT_PULLUP);
  Serial.begin(9600);
  ellapsed = millis();
}

void loop() {
  if (millis() - ellapsed > 50) {

    // inverse due to INPUT_PULLUP
    bool right = !digitalRead(BT_A);
    bool left = !digitalRead(BT_B);

    ellapsed = millis();
    if (right == true && left == true) {
      Serial.println('X');
    } else if (right == true) {
      Serial.println('R');
    } else if (left == true) {
      Serial.println('L');
    }
  }
}
