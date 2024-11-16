#include <Adafruit_NeoPixel.h>

int neoPixelPin = 0;
int numPixels = 1;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setPixelColor(0,0,0,255);

  strip.show();
  strip.clear();
}