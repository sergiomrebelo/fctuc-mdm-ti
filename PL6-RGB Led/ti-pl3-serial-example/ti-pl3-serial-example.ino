int c = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }
}

void loop() {
  // concatenate and send strings
  Serial.println("Hello "+(String)c+"World");;

  // send each string separately and close line at end
  Serial.print("Hello ");
  Serial.print("World")
  Serial.println();

  // send a string as line
  Serial.println("Hello World");

  // delay(300);
  c = c + 1;
}
