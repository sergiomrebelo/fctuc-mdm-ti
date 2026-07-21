#include <CapacitiveSensor.h>

CapacitiveSensor cs_7_6 = CapacitiveSensor(7, 6);
const int THRESHOLD = 300;


void setup() {
  // turn off autocalibrate on channel 1 - just as an example
  cs_7_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop() {
  // long start = millis();
  long total = cs_7_6.capacitiveSensor(30);

  // Uncomment the next lines to check the sensor output values
  // Serial.print(millis() - start); // check performance in ms
  // Serial.print("\t");             // tab character spacing

  if (total > THRESHOLD) {
    Serial.println(String("touch:")+total); // print sensor output 1
  }

  delay(10);
}