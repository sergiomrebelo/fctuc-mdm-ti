import processing.serial.*;

Serial myPort;

void setup() {
  printArray(Serial.list());
  //change the 0 to a 1 or 2 etc. to match your port
  String portName = Serial.list()[4];
  myPort = new Serial(this, portName, 9600);
  myPort.clear();
}

void draw() {
  if (myPort.available()>0)
  {
    int readChar=myPort.read();
    println(char(readChar));
  }
}
