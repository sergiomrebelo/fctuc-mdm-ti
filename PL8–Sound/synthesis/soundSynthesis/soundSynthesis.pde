/**
 * Tecnologias de Interface, Winter 2023
 * Universidade de Coimbra
 * MSc in Design and Multimedia
 *
 * Week 7 — Exercise 4
 * Sound Synthesis
 *
 * @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
 * @since:   28–04–2023
 * @based:   Processing Sound example
 */
 
import processing.sound.*;

SqrOsc square;

void setup() {
  size(640, 360);
  background(255);
  
  // create and start the sine oscillator.
  square = new SqrOsc(this);
  square.play();
} 
void draw() {
  // Map mouseY from 0.0 to 1.0 for amplitude
  float amplitude = map(mouseY, 0, height, 1.0, 0.0);
  square.amp(amplitude);

  // Map mouseX from 20Hz to 1000Hz for frequency  
  float frequency = map(mouseX, 0, width, 80.0, 1000.0);
  square.freq(frequency);
}
