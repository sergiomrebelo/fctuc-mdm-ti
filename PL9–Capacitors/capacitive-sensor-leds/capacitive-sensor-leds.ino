/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 9
* Exercice 8.1
* Turn on two leds using Capitive Sensor 
* 
* @authors: Ana Cláudia Rodrigues, Sérgio M. Rebelo, Tiago Cruz, and Paul Badger
* @since:   05–05–2023      
* @based:   CapacitiveSensor library examples
*/

#include <CapacitiveSensor.h>


// 10M resistor between pins 7 & 6, // pin 6 is sensor pin, add a wire and or foil if desired
CapacitiveSensor cs_7_6 = CapacitiveSensor(7, 6);
CapacitiveSensor cs_5_4 = CapacitiveSensor(5, 4);

void setup() {
  // turn off autocalibrate on channel 1 - just as an example
  cs_7_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_5_4.set_CS_AutocaL_Millis(0xFFFFFFFF);

  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  long start = millis();
  long total1 = cs_7_6.capacitiveSensor(30);
  long total2 = cs_5_4.capacitiveSensor(30);

  // Uncomment the next lines to check the sensor output values
  // Serial.print(millis() - start); // check performance in ms
  // Serial.print("\t");             // tab character spacing
  // Serial.println(total1);         // print sensor output 1

  if (total1 > 600) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }

  if (total2 > 600) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }

  // arbitrary delay to limit data to serial port
  // delay(10);
}
