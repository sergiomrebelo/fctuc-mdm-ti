/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 4
* Control a rgb led with arduino
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   24–02–2023      
*/

// sizeof returns the number of bytes in an array
// if you want the length of the array, divide the number of bytes in the array by the number of bytes in the data type.
#define ELEMENTS(x, type) (sizeof(x)/sizeof(type))  

const int pins[3] = { 13, 12, 11 };  // RGB pins of led

void setup() {
  // Initialize serial data rate (bits per second) and wait for port to open
  Serial.begin(9600);
  while (!Serial) { ; }

  // init the RGB leds
  for (int i = 0; i < ELEMENTS(pins, int); i++) {
    int p = pins[i];
    pinMode(p, OUTPUT);
  }
  // define the inital value of led
  redefineLEDs();
}

void loop() {
  // waiting by a 'R' char to redefine leds values
  while (Serial.available()) {
    char incomingByte = (char)Serial.read();
    if (incomingByte == 'R') {
      redefineLEDs();
    }
  }
}

void redefineLEDs() {
  String out = "| ";
  for (int i = 0; i < ELEMENTS(pins, int); i++) {
    int p = pins[i];
    // returns a random number between min and max-1.
    long value = random(2);
    digitalWrite(p, value);
    out = (String) out + value + " | "; 
  }
  Serial.println (out);
}
