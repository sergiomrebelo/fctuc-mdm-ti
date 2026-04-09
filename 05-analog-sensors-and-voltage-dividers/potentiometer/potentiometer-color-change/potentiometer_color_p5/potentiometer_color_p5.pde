import processing.serial.*;

final float SPEED = 2.0;

Serial myPort;
float sensorValue = 0, pSensorValue = sensorValue;
float h = 0, target = 0;

void setup() {
  size(600, 400);

  String portName = Serial.list()[4];//entrada
  printArray( Serial.list());
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
  myPort.clear();

  colorMode(HSB, 360, 100, 100);
}

void draw() {
  // println (sensorValue);

  // redundante
  // só muda target se o valor vindo do hardware mudar
  if (pSensorValue != sensorValue) {
    target = map(sensorValue, 0, 1023, 0, 360);
    target = constrain(target, 0, 360);
    pSensorValue = sensorValue;
  }


  // animação suave
  // h desloca-se gradualmente até ao target
  if (abs(h - target) > 0.5) {
    if (h < target) {
      h = h + SPEED;
      if (h > target) {
        h = target;
      }
    } else {
      h = h - SPEED;
      if (h < target) {
        h = target;
      }
    }
  }
  background(h, 100, 100);

  // alteração direta
  // background(target, 100, 100);
}

void serialEvent(Serial myPort) {
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    inString = trim(inString);
    // valor do potenciômetro
    if (inString.startsWith("p:")) {

      // remover "p:"
      String numPart = inString.substring(2);
      try {
        sensorValue = float(numPart);
      }
      catch (Exception e) {
        println("Invalid number received: " + numPart);
      }
    }
  }
}
