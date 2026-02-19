const long X_INPUT = A1;
const long Y_INPUT = A2;
const long Z_INPUT = A3;

const double SENSIBILITY = 0.33;  // V/g for ADXL335
const double ZERO_G = 1.65;

// take multiple samples to reduce noise
const long SAMPLE_SIZE = 10;

void setup() {
  // Not supported on Uno R4
  // analogReference(EXTERNAL);

  // Supported on Uno R4
  analogReference(AR_EXTERNAL);

  Serial.begin(9600);
}

void loop() {
  // read axis analog values
  double xRaw = readAxis(X_INPUT);
  double yRaw = readAxis(Y_INPUT);
  double zRaw = readAxis(Z_INPUT);

  // Convert to voltage
  double xVoltage = (xRaw * 5) / 1023.0;
  double yVoltage = (yRaw * 5) / 1023.0;
  double zVoltage = (zRaw * 5) / 1023.0;

  // Convert to acceleration in 'g'
  // Assuming 1.65V is 0g and sensitivity is 330mV/g
  double xAccel = (xVoltage - ZERO_G) / SENSIBILITY;
  double yAccel = (yVoltage - ZERO_G) / SENSIBILITY;
  double zAccel = (zVoltage - ZERO_G) / SENSIBILITY;

  // Roll and Pitch calculation
  double roll = atan2(yAccel, zAccel) * 180 / PI;
  double pitch = atan2(-xAccel, sqrt(yAccel * yAccel + zAccel * zAccel)) * 180 / PI;



  // Serial.print("Roll: " + (String)roll + "° ");
  // Serial.println("Pitch: " + (String) + pitch + "°");
  // Serial.print("x: " + (String)xRaw + " | ");
  // Serial.print("yAccel: " + (String)yRaw + " | ");
  // Serial.println("zAccel: " + (String)zRaw);

  // sent results to p5
  Serial.println((String)roll+"/"+(String)pitch);

  delay(500);
}

// reading axis sampes and return the average
long readAxis(long axisPin) {
  long reading = 0;
  analogRead(axisPin);
  for (int i = 0; i < SAMPLE_SIZE; i++) {
    reading = reading + analogRead(axisPin);
  }
  return reading / SAMPLE_SIZE;
}
