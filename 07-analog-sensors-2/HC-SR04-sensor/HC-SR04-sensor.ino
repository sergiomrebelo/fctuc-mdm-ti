/**
* Tecnologias de Interface, Winter 2026
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 7
* HC-SR04 Ping distance sensor:
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   12–04–2023      
*/


const int ECHO_PIN = 7;  // Echo Pin
const int TRIG_PIN = 8;  // Echo Pin
const int LED_PIN = LED_BUILTIN;

long duration;
float distance;  // Duration used to calculate distance

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);  // Use LED indicator (if required)
}

void loop() {
  /* The following trigPin/echoPin cycle is used to determine the
  distance of the nearest object by bouncing soundwaves off of it. */

  // phase one
  // trigger pulse input
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  // phase two
  // the sensor automatically emits 8 ultrasonic pulses

  // phase three
  // the ECHO_PIN still HIGH while wait by echo (timeout last value)
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH, 100000);

  // Calculate the distance (in cm) based on the speed of sound.
  distance = (duration * 0.034) / 2;  // or duration/29/2

  Serial.println("distance:"+(String)round(distance) + "cm");

  // Delay 60ms before next reading.
  delay(60);
}