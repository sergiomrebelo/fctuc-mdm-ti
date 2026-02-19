const long R = 13;
const long INTERVAL = 1000; 
unsigned long previous = 0;

void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
}

void loop() {
  // sent data each INTERVAL
  unsigned long current = millis();
  if (current - previous >= INTERVAL) {
    previous = current;
    Serial.println("Hello!");
  }

  // read data from serial port
  if (Serial.available() > 0) {
    int incomingByte = Serial.read();

    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);

    if (incomingByte == 0) {
      digitalWrite(R, LOW);
    } else if (incomingByte == 1) {
      digitalWrite(R, HIGH);
    }
  }



}
