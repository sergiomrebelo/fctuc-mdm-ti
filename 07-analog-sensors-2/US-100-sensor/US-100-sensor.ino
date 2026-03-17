const long TRIG_PIN =  9;
const long ECHO_PIN = 10;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  double distance = (duration / 29 / 2); // duration * 0.0343 / 2; // in cm

  Serial.println("Distance: "+(String)distance+" cm");
  delay(500);
}
