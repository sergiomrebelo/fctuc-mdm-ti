#include <CapacitiveSensor.h>

CapacitiveSensor cs_7_6 = CapacitiveSensor(7, 6);

void setup() {
  // turn off autocalibrate on channel 1 - just as an example
  cs_7_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop() {
  long start = millis();
  long total1 = cs_7_6.capacitiveSensor(30);

  // Uncomment the next lines to check the sensor output values
  // Serial.print(millis() - start); // check performance in ms
  // Serial.print("\t");             // tab character spacing
  Serial.println(total1);         // print sensor output 1

  if (total1 > 450) {
    Serial.println("touch");
  }
  
  delay(10);
}