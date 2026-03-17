/**
 * Tecnologias de Interface, Winter 2023
 * Universidade de Coimbra
 * MSc in Design and Multimedia
 *
 * Week 7 — Exercise 5
 * Sound Synthesis with a envelope and a triangular wave oscillator 
 *
 * @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
 * @since:   28–04–2023
 * @based:   Processing Sound example
 */
 
import processing.sound.*;

TriOsc triOsc;
Env env;

float attackTime = 0.001;
float sustainTime = 0.004;
float sustainLevel = 0.3;
float releaseTime = 0.4;

void setup() {
  size(640, 360);
  background(255);
  
  // Create triangle wave
  triOsc = new TriOsc(this);

  // Create the envelope 
  env  = new Env(this); 
 
}      

void draw() {}

void mousePressed() {
  triOsc.play();
  env.play(triOsc, attackTime, sustainTime, sustainLevel, releaseTime);
}
