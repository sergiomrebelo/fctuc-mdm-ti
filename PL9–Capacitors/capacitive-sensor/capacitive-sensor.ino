/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 9
* Exercice 8
* CapitiveSense Library Demo Sketch, Paul Badger 2008
* Uses a high value resistor e.g. 10M between 
* send pin and receive pin
* Receive pin is the sensor pin - try different 
* amounts of foil/metal on this pin
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   16–03–2023      
* @based:   CapacitiveSensor library examples
*/

#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch, Paul Badger 2008
 * Uses a high value resistor e.g. 10M between 
 * send pin and receive pin
 * Receive pin is the sensor pin - try different 
 * amounts of foil/metal on this pin
 */

// 10M resistor between pins 7 & 6, // pin 6 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_7_6 = CapacitiveSensor(7,6); 
       
void setup() {
 // turn off autocalibrate on channel 1 - just as an example
   cs_7_6.set_CS_AutocaL_Millis(0xFFFFFFFF);     
   Serial.begin(9600);
}

void loop() {
    long start = millis();
    long total1 =  cs_7_6.capacitiveSensor(30);
    
    // Uncomment the next lines to check the sensor output values
    //Serial.print(millis() - start); // check performance in ms
    //Serial.print("\t");             // tab character spacing
    // Serial.println(total1);         // print sensor output 1

    if (total1>450) Serial.println("touch");
    // arbitrary delay to limit data to serial port
    delay(10); 
}