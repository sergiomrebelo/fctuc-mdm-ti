/**
* Tecnologias de Interface, 2026
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 5
* LDR example
* 
* @authors: Sérgio M. Rebelo and Tiago Cruz
* @since:   16–03–2023      
*/

const long LDR_PIN = A0; 
const long LED_PIN = 13; 

long value = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}
void loop() {
  // read the value from the sensor:
  value = analogRead(LDR_PIN);
  Serial.println ("value="+String(value));

  digitalWrite(LED_PIN, HIGH);

  // stop the program for x milliseconds based on value
  delay(value);

  // turn the ledPin off:
  digitalWrite(LED_PIN, LOW);

  delay(value);
}