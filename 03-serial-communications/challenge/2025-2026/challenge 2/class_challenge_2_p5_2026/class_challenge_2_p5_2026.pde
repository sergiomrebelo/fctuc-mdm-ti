import processing.serial.*;

Serial myPort;
int lf = 10, r = 100;
boolean state = false;

void setup() {
  size (500,500);
  String portName = Serial.list()[4];
  printArray(Serial.list());
  
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil(lf); // '\n' or 10
  myPort.clear();
  
  ellipseMode(RADIUS);
}

// Event based reading
void serialEvent(Serial p) {
  try {
    String val = p.readString ();  // or readStringUntil('\n');
    if (val!=null) {
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
  color c = (state == true) ? color (255,0,0) : color(255);
  fill(c);
  circle(width/2, height/2, r);
  
  // pooling-based
  // if (myPort.available()>0)
  // {
  //   int readChar=myPort.read();
  //   println(char(readChar));
  // }
  
  
}

void mousePressed() {
  float d = dist(mouseX, mouseY, width/2, height/2);
  if (d < r) {
    state = !state;
    String c = (state == true) ? "H" : "L";
    println ("value sent:", c);
    myPort.write(c);
  }
}
