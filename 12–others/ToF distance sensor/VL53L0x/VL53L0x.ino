#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X tof = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);
  // while (!Serial) {}
  Serial.println("Adafruit VL53L0X test.");
  
  if (!tof.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
  Serial.println(F("VL53L0X API Continuous Ranging example\n\n"));
  tof.startRangeContinuous();
}

void loop() {
  if (tof.isRangeComplete()) {
    Serial.print("Distance in mm: ");
    Serial.println(tof.readRange());
  }
}
