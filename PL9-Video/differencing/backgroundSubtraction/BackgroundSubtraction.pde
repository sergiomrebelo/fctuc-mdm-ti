/**
 * Tecnologias de Interface, Winter 2023
 * Universidade de Coimbra
 * MSc in Design and Multimedia
 *
 * Week 8
 * Background Subtraction
 * Detect the presence of people and objects in the frame using a simple
 * background-subtraction technique. To initialize the background, press a key.
 *
 * @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, Tiago Cruz, and Golan Levin.
 * @since:   04–05–2023
 * @based:   Golan Levin's Background Subtraction
 */

import processing.video.*;

int numPixels;
int[] backgroundPixels;

Capture cam;

void setup() {
  size(640, 480);

  String[] devices = Capture.list();

  if (devices.length == 0) {
    println("There are no cameras available for capture.");
    exit();
  }

  cam = new Capture(this, 640, 480, devices[0]);
  cam.start();

  // Create array to store the background image
  numPixels = cam.width * cam.height;
  backgroundPixels = new int[numPixels];

  loadPixels();
}

void draw() {
  if (cam.available()) {
    cam.read();
    cam.loadPixels();
    // Difference between the current frame
    // and the stored background
    int movement = 0;
    for (int i = 0; i < numPixels; i++) { // For each pixel in the video frame...
      color current = cam.pixels[i];
      color bkgd = backgroundPixels[i];
  
      int diffR = (int) abs(red (current) - red (bkgd));
      int diffG = (int) abs(green (current) - green (bkgd));
      int diffB = (int) abs(blue (current) - blue (bkgd));

      movement += diffR + diffG + diffB;

      pixels[i] = color(diffR, diffG, diffB);
    }
    updatePixels();
    // Print out the total amount of movement
    // println(movement);
  }
}

// When a key is pressed, capture the background image into the backgroundPixels
// buffer, by copying each of the current frame's pixels into it.
void keyPressed() {
  cam.loadPixels();
  arrayCopy(cam.pixels, backgroundPixels);
}
