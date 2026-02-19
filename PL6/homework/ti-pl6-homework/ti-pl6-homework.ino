long leftBt = 6, rightBt = 7;
long ellapsed = -1; // block to many attempts
long interval = 10;

void setup() {
  pinMode(leftBt, INPUT_PULLUP);
  pinMode(rightBt, INPUT_PULLUP);
  Serial.begin(9600);

  ellapsed = millis(); 
}

void loop() {
  
  if (millis() - ellapsed > interval) {
    boolean left = !digitalRead(leftBt);
    boolean right = !digitalRead(rightBt);

    ellapsed = millis();
    
    if (left == true && right == true) {
      Serial.println ("X");
    } else if (left == true) {
      Serial.println ("L");
    } else if (right == true) {
      Serial.println ("R");
    }
  }

}
