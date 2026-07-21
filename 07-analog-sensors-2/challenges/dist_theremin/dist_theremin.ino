/* MSc in Design and Multimedia
 *
 * Week 8
 * HC-SR04 Theremin
 *
 */


const int ECHO_PIN = 7;  // Echo Pin
const int TRIG_PIN = 8; // Trigger Pin
const int BUZZER_PIN = 9;

// variable to hold sensor value
int sensorValue;

int maximumRange = 100;  // Maximum range needed
int minimumRange = 0;    // Minimum range needed
int duration, distance;  // Duration used to calculate distance

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  /* The following trigPin/echoPin cycle is used to determine the
   distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH, 30000);

  //Calculate the distance (in cm) based on the speed of sound.
  distance = (duration * .0343) / 2;



  // map the sensor values to a wide range of pitches
  long pitch = map(distance, minimumRange, maximumRange, 50, 4000);

  Serial.println ("distance:"+(String)distance);
  Serial.println ("pitch:"+(String)pitch);

  if (!((distance >= maximumRange) || (distance <= minimumRange))) {
    // play the tone for 20 ms on pin 9
    tone(9, pitch, 20);
  }
  // wait for a moment
  delay(10);
}