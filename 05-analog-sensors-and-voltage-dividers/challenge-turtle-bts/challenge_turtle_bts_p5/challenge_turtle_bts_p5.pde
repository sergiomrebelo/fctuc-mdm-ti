import processing.serial.*;

Serial myPort;
String val;
PVector heading, turtle;
long count = 0;

void setup() {
  size(800, 800);
  String portName = Serial.list()[4];
  // printArray(Serial.list());
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
  myPort.clear();

  heading= new PVector(1, 0);
  turtle= new PVector(400, 400);
}

void draw() {
  ellipse(turtle.x, turtle.y, 10, 10);
  turtle.add(heading);

  // remove from template
  // if (count==0) {
  //  heading.rotate(random(-10, 10));
  // }
  // count=(count+1)%100;
}


void serialEvent(Serial myPort) {
  try {
    val = myPort.readStringUntil('\n');
    String cmd = trim(val);
    if (cmd!=null) {
      if (cmd.equals("R")) {
        heading.rotate(radians(10));
      } else if (cmd.equals("L")) {
        heading.rotate(radians(-10));
      } else if (cmd.equals("X")) {
        exit();
      }
    }
  }
  catch (Exception e) {
    e.printStackTrace();
  }
}
