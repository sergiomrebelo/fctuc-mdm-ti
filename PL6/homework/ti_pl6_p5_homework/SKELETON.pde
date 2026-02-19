//Controle da bola com as teclas 'L' e 'R' (maiúsculas)

import processing.serial.*;
Serial myPort;
String val;

ball b;

void setup() {
  size(1024, 1024);
  b=new ball(width/2, height/2, 20);
  ellipseMode(CENTER);
  
  // select the port
  String [] ports = Serial.list();
  printArray(ports);
  String portName = ports[4];
  myPort = new Serial(this, portName, 9600);
  
  // clearning the buffer
  myPort.clear();
}

void draw() {
  background(255);

  b.move();
  b.show();
  b.collide();
}

void keyPressed() {
  b.steer(key);
}

void serialEvent(Serial myPort) {
  try {
    // if both keys pressed, random select a new position
    char cmd = (char) myPort.read();
    println ("cmd=", cmd);
    if (cmd == 'X') {
      // cmd = random(1) > 0.5 ? 'L' : 'R';
      exit();
    }
    b.steer(cmd);
  }
  catch (Exception e) {
    e.printStackTrace();
  }
}
