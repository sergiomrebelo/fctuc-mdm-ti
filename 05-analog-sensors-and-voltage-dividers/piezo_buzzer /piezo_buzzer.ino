/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 7
* Piezo Buzzer 
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   16–03–2023      
* @basedon: arduino example
*/

const int LDR_PIN = A0;
const int LED_PIN = LED_BUILTIN;
const int BUZZER_PIN = 8;
const bool calibrate = false;

int lightValue = 0;   // variable to store the value coming from the sensor
int lightLow = 1023;  // variable to calibrate low value
int lightHigh = 0;    // variable to calibrate high value


void setup() {
  // Make the LED pin an output and turn it on
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  // calibrate for the first five seconds after program runs
  if (calibrate) {
    while (millis() < 5000) {
      // record the maximum sensor value
      lightValue = analogRead(A0);
      if (lightValue > lightHigh) {
        lightHigh = lightValue;
      }
      // record the minimum sensor value
      if (lightValue < lightLow) {
        lightLow = lightValue;
      }
    }
  }

  // turn the LED off, signaling the end of the calibration period
  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);
  while (!Serial) {
    ;
  }
}

void loop() {
  //read the input from A0 and store it in a variable
  lightValue = analogRead(LDR_PIN);

  // map the sensor values to a wide range of pitches
  int pitch = map(lightValue, lightLow, lightHigh, 50, 4000);

  // play the tone for 20 ms on pin 8
  tone(BUZZER_PIN, pitch, 20);

  Serial.println((String) "current pitch: " + pitch + "(" + lightValue + ")");

  delay(100);
}
