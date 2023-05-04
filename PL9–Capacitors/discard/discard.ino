/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 9
* Exercice 7
* analog pin used to measure the voltage of the capacitor 
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   16–03–2023      
*/


#define analogPin 0
// capacitor charging pin    
#define chargePin 3

unsigned long startTime;
unsigned int readVolt;

void  setup () {
  pinMode (chargePin, OUTPUT );
  digitalWrite (chargePin, LOW );  
  Serial.begin (9600);              // initialize serial communication
  startTime = micros ();           
}

void loop(){
  /* Discharge capacitor */ 
  // load set pin as output - low impedance
  pinMode (chargePin, OUTPUT );      
  digitalWrite (chargePin, LOW );      
       
  readVolt = analogRead (analogPin);   // read the value 
  // wait until the capacitor is discharged 
  while (readVolt> 0) {	   
    // print the analog value 
    Serial.println ((readVolt*(5/1024.0)));   
    readVolt = analogRead (analogPin);   // read voltage;
   }

  digitalWrite (chargePin, HIGH );   // charge the capacitor 
  readVolt = analogRead (analogPin);   // read sensor
  while (readVolt <1017) {    // 1016 is the expected value at 5 TC 
    Serial.println ((readVolt*(5/1024.0)));         
    readVolt = analogRead (analogPin);   // read voltage
  }
}