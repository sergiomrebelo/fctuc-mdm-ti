const long BUTTON_X = A0, BUTTON_Y = A1;
// callibration
const long CALIBRATION_TIME = 10000;
long maxX = 1025, minX = -1, maxY = 1025, minY = -1;
// ellapsed time
long elapsed = -1;

void setup() {
  Serial.begin(9600);
  elapsed = millis();

  // Calibration: max and min values when still
  // run a small loop on the setup
  // the user is not spose to touch joystick
  // and system will collect the interval readings during rest
  while ((millis() - elapsed) < CALIBRATION_TIME) {
    long x = analogRead(BUTTON_X);
    long y = analogRead(BUTTON_Y);
    maxX = min(x, maxX);
    maxY = min(y, maxY);
    minX = max(x, minX);
    minY = max(y, minY);
  }
  // End of calibration
  Serial.println ("resting position of x ["+(String)minX+","+(String)maxX+"]");
  Serial.println ("resting position of y ["+(String)minY+","+(String)maxY+"]");
}

void loop() {
  if (millis() - elapsed > 100) {
    long x = analogRead(BUTTON_X);
    long y = analogRead(BUTTON_Y);

    // Serial.println("x: " + (String)x);
    // Serial.println("y: " + (String)y);

    elapsed = millis();
  }
}
