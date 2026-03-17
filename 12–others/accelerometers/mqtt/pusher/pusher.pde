import processing.serial.*;
import mqtt.*;

final String CLIENT_ID = "CLIENT"+millis();

Serial myPort;
MQTTClient client;

float roll, pitch;

void setup() {
  String[] ports = Serial.list();
  printArray(ports);
  myPort = new Serial(this, ports[4], 9600);
  myPort.bufferUntil('\n');

  client = new MQTTClient(this);
  client.connect("mqtt://public:public@public.cloud.shiftr.io", CLIENT_ID);
}

void draw() {
  client.publish("/roll", str(roll));
  client.publish("/pitch", str(pitch));
  println ("roll = "+roll+" | pitch = "+pitch);
}

void serialEvent (Serial myPort) {
  String data = myPort.readStringUntil('\n');
  if (data != null) {
    data = trim(data);
    String items[] = split(data, '/');
    if (items.length > 1) {
      roll = float(items[0]);
      pitch = float(items[1]);
    }
  }
}

void messageReceived(String topic, byte[] payload) {
  println("new message: " + topic + " - " + new String(payload));
}
