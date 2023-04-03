/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 7
* TMP36
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   16–03–2023      
* @basedon: https://learn.adafruit.com/thermistor/using-a-thermistor
*/

int sensorPin = A0; 

void setup() {
  Serial.begin(9600);                      
}
 
void loop() {
 //getting the voltage reading from the sensor
 int reading = analogRead(sensorPin);  
 
 // converting the ADC reading to voltage
 float voltage = (reading * 5.0)/1024;
  
 // Print the temperature
 float temperatureC = (voltage - 0.5) * 100 ;  
 Serial.println(temperatureC); 
 
 delay(1000);                                     
}