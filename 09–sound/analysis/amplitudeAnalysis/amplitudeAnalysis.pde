/**
 * Tecnologias de Interface, Winter 2023
 * Universidade de Coimbra
 * MSc in Design and Multimedia
 *
 * Week 7 — Exercise 2
 * Amplitude Analysis
 *
 * @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
 * @since:   28–04–2023
 * @based:   Processing Sound example
 */

import processing.sound.*;

AudioIn in;
Amplitude amp;
float prev;
int i=0;

void setup() {
  size(512, 200, P2D);

  in = new AudioIn(this, 0);
  in.start();
  
  amp = new Amplitude(this);
  amp.input(in);
  prev=amp.analyze();
  
  background (0);
  stroke(255);
}

void draw() {
  if (i==0) background(0);
  float newSample=amp.analyze();
  line( i, 100 -prev*100, i+1, 100 -newSample*100 );
  i= (i+1) % width;
  prev=newSample;
}
