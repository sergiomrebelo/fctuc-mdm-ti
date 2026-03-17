import processing.serial.*;
Serial p;

boolean on = false;
int r = 100;

void setup() {
  // fullScreen();
  size(500, 500);

  noStroke();
  ellipseMode(CENTER);
  
  String portName = Serial.list()[4];
  p = new Serial(this, portName, 9600);
  p.clear();
}

void draw() {
  background(150);
  color c = on == true ? color(255, 0, 0) : color(0);
  fill(c);
  circle(width/2, height/2, r*2);
}

void mousePressed() {
  float d = dist (mouseX, mouseY, width/2, height/2);
  if (d < r) {
    on = !on;
    char info = on == true ? 'H' : 'L';
    p.write(info);
  }
}
