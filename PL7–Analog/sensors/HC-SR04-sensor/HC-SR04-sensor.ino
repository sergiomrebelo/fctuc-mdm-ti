/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 7
* HC-SR04 Ping distance sensor:
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   16–03–2023      
*/

#define echoPin 7  // Echo Pin
#define trigPin 8  // Trigger Pin
#define LEDPin 13

long duration;
float distance;  // Duration used to calculate distance

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT);  // Use LED indicator (if required)
}

void loop() {
  /* The following trigPin/echoPin cycle is used to determine the
  distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 100000);

  //Calculate the distance (in cm) based on the speed of sound.
  distance = (duration * 0.034) / 2;  // or duration/29/2

  Serial.println((String)round(distance)+"cm");

  //Delay 60ms before next reading.
  delay(60);
}