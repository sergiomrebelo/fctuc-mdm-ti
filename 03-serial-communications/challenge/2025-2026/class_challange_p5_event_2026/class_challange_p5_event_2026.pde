import processing.serial.*;

Serial myPort;
int lf = 10;
int r = 100;
boolean state = false;

void setup() {
  size (500,500);
  String portName = Serial.list()[4];
  printArray(Serial.list());
  myPort = new Serial(this, portName, 3000);
  myPort.bufferUntil(lf); // '\n' or 10
  myPort.clear();
  ellipseMode(CENTER);
}

void serialEvent(Serial p) {
  try {
    String val = p.readString ();  // or readStringUntil('\n');
    if (val!=null) {
      // int level=int(val.substring(0, val.length()-2));
      // val = val.substring(0, val.length()-2);
      val = val.trim();
      println ("received: "+val);
    }
  }
  catch (Exception e) {
    e.printStackTrace();
  }
}

void draw() {
  background(0);
  color c = state == true ? color (255,0,0) : color(255);
  fill(c);
  circle(width/2, height/2, r*2);
}

void mousePressed() {
  float d = dist(mouseX, mouseY, width/2, height/2);
  if (d < r) {
    myPort.write('R');
    state = !state;
  }
}

void keyPressed() {
  switch ((""+key).toUpperCase()) {
    case "R":
    println ("info: sent R");
    myPort.write('R');
    break;
    case "G":
    println ("info: sent G");
    myPort.write('G');
    break;
  }
}
