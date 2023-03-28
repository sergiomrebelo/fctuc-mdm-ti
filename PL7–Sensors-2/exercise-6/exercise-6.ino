/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Exercise 6
* ultrasonic distance theremin
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   16–03–2023      
* @basedon: https://learn.adafruit.com/thermistor/using-a-thermistor
*/


#define echoPin 7  // Echo Pin
#define trigPin 8  // Trigger Pin

// variable to hold sensor value
int sensorValue;

int maximumRange = 300;  // Maximum range needed
int minimumRange = 0;    // Minimum range needed
int duration, distance;  // Duration used to calculate distance

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  /* The following trigPin/echoPin cycle is used to determine the
   distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 30000);

  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration / 58.2;

  // map the sensor values to a wide range of pitches
  int pitch = map(distance, minimumRange, maximumRange, 50, 4000);
  Serial.println((String) "dist=" + distance);

  if (!((distance >= maximumRange) || (distance <= minimumRange))) {
    // play the tone for 20 ms on pin 9
    tone(9, pitch, 20);
  }
  // wait for a moment
  delay(10);
}
