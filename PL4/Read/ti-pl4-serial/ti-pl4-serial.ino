long value = 1;

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
}

void loop() {
  Serial.println(value);
  // Prints data to the serial port as human-readable ASCII text.
  // println() sends values as strings, terminating with CR+LF
  Serial.println("1: Hello world!");

  // concat strings to sent to serial port
  Serial.println(String("2: ") + "Hello world!");

  // concat various type of data into string and sent to serial port
  Serial.println(String(3) + ": Hello world!");

  // print() is the simplest version, without CR+LF
  // CR+LF stands for Carriage Return + Line Feed, which is a sequence of two control characters (\r\n) 
  // used to represent a new line in some operating systems and protocols.
  String w = "world!";
  Serial.print(4);
  Serial.print(": Hello ");
  Serial.println(w);

  delay(500);
}
