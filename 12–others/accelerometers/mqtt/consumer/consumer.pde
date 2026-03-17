import mqtt.*;

final String CLIENT_ID="CLIENT"+millis();
MQTTClient client;

String data = "";
PFont caption;

float roll = 0, pitch = 0, rollFilter = 0, pitchFilter = 0;

void setup() {
  randomSeed(millis());
  size (960, 640, P3D);

  client = new MQTTClient(this);
  client.connect("mqtt://public:public@public.cloud.shiftr.io", CLIENT_ID);
  
  caption = createFont("NittiTypewriter-Normal", 18);
}

void clientConnected() {
  println("client connected");
  client.subscribe("/roll");
  client.subscribe("/pitch");
}

void draw() { 
  background(10);

  push();
  translate(width/2, height/2, 0);
  rotateX(radians(rollFilter));
  rotateZ(radians(pitchFilter));
  fill(0, 170, 150);
  box (400, 45, 200); // Draw box
  pop();

  textFont(caption);
  fill(255);
  String s = "Roll = " + int(roll) + " | Pitch = " + int(pitch);
  text(s, width/2-textWidth(s)/2, 30);
}


void messageReceived(String topic, byte[] payload) {
  String value=new String(payload);
  
  if (topic.equals("/roll")) {
    roll = float(value);
    // low pass filter (smoothing)
    rollFilter = 0.94 * rollFilter + 0.06 * roll;
  }
  else if (topic.equals("/pitch")) {
    pitch = float(value);
    // low pass filter (smoothing)
    pitchFilter = 0.94 * pitchFilter + 0.06 * pitch;
  }  
}
