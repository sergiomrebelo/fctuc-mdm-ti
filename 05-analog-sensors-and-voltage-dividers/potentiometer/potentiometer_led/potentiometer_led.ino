/**
* Tecnologias de Interface, 2026
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 5
* Potentiometer example
* 
* @authors: Sérgio M. Rebelo and Tiago Cruz
* @since:   16–03–2023      
*/

const long POT_PIN = A1;
const long LDR_PIN = A0;
const long LED_PIN = 13;


void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}
void loop() {
  // read the value from the sensor:
  long LDRValue = analogRead(LDR_PIN);
  long PotValue = analogRead(POT_PIN);

  Serial.println("LDRValue=" + String(LDRValue));
  Serial.println("PotValue=" + String(PotValue));

  digitalWrite(LED_PIN, HIGH);

  // stop the program for x milliseconds based on value
  delay(PotValue);

  // turn the ledPin off:
  digitalWrite(LED_PIN, LOW);

  delay(PotValue);
}