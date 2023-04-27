/**
 * Tecnologias de Interface, Winter 2023
 * Universidade de Coimbra
 * MSc in Design and Multimedia
 *
 * Week 7 — Exercise 1
 * Wave Analysis
 *
 * @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
 * @since:   28–04–2023
 * @based:   Processing Sound example
 */
 
import processing.sound.*;

AudioIn in;
Waveform waveform;
int samples= 512;

void setup() {
  size(512, 200, P2D);
  printArray(Sound.list());
  
  in = new AudioIn(this, 0);
  in.start();
  
  waveform = new Waveform(this, samples);
  waveform.input(in);
}

void draw(){
  background(0);
  stroke(255);
  
  waveform.analyze();
  
  for (int i = 0; i < (waveform.data).length-1; i++) {
    line( i, 100 + waveform.data[i]*100, i+1, 100 + waveform.data[i+1]*100 );
  }
}
