import mqtt.*;

// Generate a unique MQTT client ID
final String CLIENT_ID = "CLIENT" + millis();

MQTTClient client;
String previous = "";

void setup() {
  // Initialise the MQTT client
  client = new MQTTClient(this);

  // Connect to the public broker on shiftr.io with username:password
  // Note: You can visualize the connection at https://www.shiftr.io/try?lang=processing
  client.connect("mqtt://public:public@public.cloud.shiftr.io", CLIENT_ID);

  size(1080, 720);
  background(0);
  textAlign(CENTER, CENTER);
  PFont font = createFont("NittiGrotesk-Bold", 48);
  textFont(font);
}

// Callback that runs when the client successfully connects
void clientConnected() {
  println("client connected");
  // Subscribe to the "/p5" topic to receive messages
  client.subscribe("/p5");
}

void draw() {
  background(0);
  fill(255);
  text(previous, width / 2, height / 2);
}

void keyPressed() {
  // publisher mode
  // When a key is pressed, publish a message to the "/p5" topic
  String msg = "Hello World! " + millis();  // Include timestamp
  client.publish("/p5", msg);
  println("Published: " + msg);
}

// Callback that triggers when a message is received from any subscribed topic
void messageReceived(String topic, byte[] payload) {
  // subscriber mode
  String msg = new String(payload);
  println("new message: " + topic + " — " + msg);
  previous = msg;
}

// Callback if the MQTT connection is lost
void connectionLost() {
  println("connection lost");
}
