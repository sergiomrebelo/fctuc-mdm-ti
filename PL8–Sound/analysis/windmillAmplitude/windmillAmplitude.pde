/**
 * Tecnologias de Interface, Winter 2023
 * Universidade de Coimbra
 * MSc in Design and Multimedia
 *
 * Week 7 — Exercise 4
 * Amplitude Windmill
 *
 * @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
 * @since:   28–04–2023
 * @based:   Processing Sound example
 */
 
import processing.sound.*;

AudioIn in;
Amplitude amp;

float arc=0;
float step=0, radius=150;

void setup() {
  size(640, 480);

  String [] devices = Sound.list();
  // printArray (devices);

  in = new AudioIn (this, 0);
  amp = new Amplitude(this);

  in.start();
  amp.input(in);
}

void draw() {
  background(0);
  stroke(255);

  float a = amp.analyze();
  step = map(a, 0, 0.5, 0.0, 0.3);
  step = constrain(step, 0, 0.2);

  arc=arc+step;
  
  triangle(320, 240, 320+radius*cos(arc-0.2), 240+radius*sin(arc-0.2), 320+radius*cos(arc+0.2), 240+radius*sin(arc+0.2));
  triangle(320, 240, 320+radius*cos(arc+PI-0.2), 240+radius*sin(arc+PI-0.2), 320+radius*cos(arc+PI+0.2), 240+radius*sin(arc+PI+0.2));
}
