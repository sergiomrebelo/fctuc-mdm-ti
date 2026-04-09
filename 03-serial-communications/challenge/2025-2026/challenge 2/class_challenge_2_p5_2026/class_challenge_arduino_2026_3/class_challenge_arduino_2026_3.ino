#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;
const uint32_t on[] = { 0xffffffff, 0xffffffff, 0xffffffff };
const uint32_t off[] = { 0x00000000, 0x00000000, 0x00000000 };

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  // auxiliar
  matrix.begin();
}

void loop() {
  if (Serial.available() > 0) {
    char v = Serial.read();
    // Serial.println ("arduino:"+String(v));
    if (v == 'H' || v == 'h') {
      digitalWrite(LED_BUILTIN, HIGH);
      matrix.loadFrame(on);
    } else if (v == 'L' || v == 'L') {
      digitalWrite(LED_BUILTIN, LOW);
      matrix.loadFrame(off);
    }
  }
}
