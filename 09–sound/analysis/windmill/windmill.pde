/**
 * Tecnologias de Interface, Winter 2023
 * Universidade de Coimbra
 * MSc in Design and Multimedia
 *
 * Week 7 — Exercise 3
 * Automatic Windmill
 *
 * @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
 * @since:   28–04–2023
 * @based:   Processing Sound example
 */
 
float arc=0;
float step=0,radius=0;

void setup(){
  size(640, 480);
  step=0.2;
  radius=150;
}

void draw() {
  background(0); 
  stroke(255);
  
  arc=arc+step;
  triangle(320,240,320+radius*cos(arc-0.2),240+radius*sin(arc-0.2),320+radius*cos(arc+0.2),240+radius*sin(arc+0.2));
  triangle(320,240,320+radius*cos(arc+PI-0.2),240+radius*sin(arc+PI-0.2),320+radius*cos(arc+PI+0.2),240+radius*sin(arc+PI+0.2));
}
