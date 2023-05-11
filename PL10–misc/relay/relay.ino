/**
 * Tecnologias de Interface, Winter 2023
 * Universidade de Coimbra
 * MSc in Design and Multimedia
 *
 * Week 10
 * Relay example
 *
 * @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz,
 * @since:   12–05–2023
 */

const int RELAY_PIN = 8;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  digitalWrite(RELAY_PIN, HIGH);  
  delay(3000);                    
  digitalWrite(RELAY_PIN, LOW); 
  delay(3000);   
}
