/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 7
* Piezo Sensor (knock sensor) 
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   16–03–2023      
*/

const int ledPin = 13;
const int knockSensor = A0;
// threshold value to decide when the detected sound is a knock or not
const int threshold = 100;

int sensorReading = 0;
// variable to store the value read from the sensor
int ledState = LOW;
// variable used to store the last LED status, to toggle the light


void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as as OUTPUT
  Serial.begin(9600);
  // use the serial port
}


void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);
  Serial.println (sensorReading);
  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer,
    // followed by newline  Serial.println("Knock!");
  }
  // delay to avoid overloading the serial port buffer
  delay(100);
}
