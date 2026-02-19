import processing.serial.*;

Serial myPort;

PVector turtle;

void setup() {
  size(800, 800);
  turtle = new PVector (width/2, height/2);

  // change to match your port
  String [] ports = Serial.list();
  // printArray(ports);
  String portName = ports[4];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
  myPort.clear();

  background (255);
  fill(0);
}

void draw() {
  turtle.x = constrain (turtle.x, 0, width);
  turtle.y = constrain (turtle.y, 0, height);
  ellipse(turtle.x, turtle.y, 5, 5);
}

void serialEvent( Serial myPort) {
  try {
    String val = myPort.readString();
    val = val.trim(); // or strip()
    String [] sp = split(val, ":");
  
    if (sp!=null) {
      if (sp.length == 2) {
        PVector joystick = new PVector(
          int(sp[0])/512f*5,
          int(sp[1])/512f*5
          );
        println(joystick);
        turtle.add(joystick);
      }
    }
  }
  catch (Exception e) {
    e.printStackTrace();
  }
}
