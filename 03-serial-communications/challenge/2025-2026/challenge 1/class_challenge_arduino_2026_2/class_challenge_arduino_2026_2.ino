#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

const long PIN_RED = 3, PIN_GREEN = 4;
boolean redState = LOW, greenState = LOW;


void setup() {
  Serial.begin(9600);
  // debug
  matrix.begin();

  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // char incomingByte = (char) Serial.read();
    String str = Serial.readStringUntil('\n');
    Serial.println((String) "received: " + str);
    if (str.equalsIgnoreCase("R")) {
      // if (incomingByte == 'R')
      redState = !redState;
    } else if (str.equalsIgnoreCase("G")) {
      greenState = !greenState;
    } else  {
      redState = LOW;
      greenState = LOW;
    }
  }

  digitalWrite(PIN_RED, redState);
  digitalWrite(PIN_GREEN, greenState);

  String r = redState == HIGH ? "3" : "/";
  String g = greenState == HIGH ? "4" : "/";

  String text = r + " " + g;
  matrix.textFont(Font_4x6);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText();

  matrix.endDraw();

  delay(2000);
}
