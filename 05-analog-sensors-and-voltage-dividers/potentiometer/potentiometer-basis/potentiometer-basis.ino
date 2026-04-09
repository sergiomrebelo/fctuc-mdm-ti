/**
* Tecnologias de Interface, 2026
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 6
* Potentiometer
* 
* @authors: Sérgio M. Rebelo, and Tiago Cruz
* @since:   19–03–2023      
*/

void setup() {
  // initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin A0
  long value = analogRead(A0);

  // change the scale of reading
  // Convert the analog reading (which goes from 0 - 1023) 
  // to a voltage (0 - 5V)
  double voltage = value * (5.0 / 1024.0);
 
 // print out the value you read
  Serial.println(voltage);
}
