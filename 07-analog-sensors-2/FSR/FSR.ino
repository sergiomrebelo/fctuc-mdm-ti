/**
* Tecnologias de Interface, Winter 2026
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 7
* Interfacing Force Sensing Resistor (FSR)
* 
* @authors: Sérgio M. Rebelo
* @since:   12–04–2026      
*/

const int FSR_PIN = A0;   
int reading;  
 
void setup(void) {
  Serial.begin(9600);   
}
 
void loop(void) {
  reading = analogRead(FSR_PIN);  
 
  Serial.print("reading:"+String(reading));
 
  if (reading < 10) {
    Serial.println(" — No pressure");
  } else if (reading < 200) {
    Serial.println(" — Light touch");
  } else if (reading < 500) {
    Serial.println(" — Light squeeze");
  } else if (reading < 800) {
    Serial.println(" — Medium squeeze");
  } else {
    Serial.println(" — Big squeeze");
  }
  delay(1000);
}