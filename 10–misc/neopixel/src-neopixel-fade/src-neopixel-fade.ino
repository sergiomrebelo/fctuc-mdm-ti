#include <Adafruit_NeoPixel.h>

// input pin Neopixel is attached to
const long PIN = 2; 
// number of neopixels in Ring
const long  NUM_PIXELS = 12;
// timing delay
const long DELAY_TIME = 100; 

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);


long r = 0, g = 0, b = 0;

void setup() {
  // Initializes the NeoPixel library.
  pixels.begin();  
}

void loop() {
  // picks random values to set for RGB
  setColor();

  for (int i = 0; i < NUM_PIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    pixels.show();    // This sends the updated pixel color to the hardware.
    delay(DELAY_TIME);  // Delay for a period of time (in milliseconds).

    // ToDO: check if necessary
    if (i == NUM_PIXELS) {
      i = 0;  // start all over again!
      setColor();
    }
  }
}

void setColor() {
  r = random(0, 255);
  g = random(0, 255);
  b = random(0, 255);
}
