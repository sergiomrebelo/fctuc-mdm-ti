const long BUTTON_X = A0, BUTTON_Y = A1;
const long BUTTON_SEL = 2;
// callibration
const long CALIBRATION_TIME = 10000;
long maxX = -1, minX = 1025, maxY = -1, minY = 1025;
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
    Serial.println("calibrating: " + (String)(millis() - elapsed));
    long x = analogRead(BUTTON_X);
    long y = analogRead(BUTTON_Y);
    maxX = max(x, maxX);
    minX = min(x, minX);

    maxY = max(y, maxY);
    minY = min(y, minY);
  }
  // End of calibration
  Serial.println("resting position of x [" + (String)minX + "," + (String)maxX + "]");
  Serial.println("resting position of y [" + (String)minY + "," + (String)maxY + "]");

  pinMode(BUTTON_SEL, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (millis() - elapsed > 100) {
    // push buttom
    const long led = !digitalRead(BUTTON_SEL);
    digitalWrite (LED_BUILTIN, led);

    // potentiometers
    long x = analogRead(BUTTON_X);
    long y = analogRead(BUTTON_Y);

    // Serial.println("x: " + (String)x + " | y:"+ (String)y);
    //Serial.println("y: " + (String)y);

    long posX = 0, posY = 0;

    if ((x < minX) || (x > maxX)) {
      posX = x - 512;
    }

    if ((y < minY) || (y > maxY)) {
      posY = y - 512;
    }

    Serial.println((String)posX + ":" + (String)posY);
    elapsed = millis();
    
  } 
}
