/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 6
* Exercise 4
* control a RGB LED with Serial.
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   24–02–2023      
*/

// sizeof returns the number of bytes in an array
// if you want the length of the array, divide the number of bytes in the array by the number of bytes in the data type.
#define ELEMENTS(x, type) (sizeof(x)/sizeof(type))  

const int pins[3] = { 13, 12, 11 };  // RGB pins of led
bool state[3] = {true, true, true}; // Led state

void setup() {
  // Initialize serial data rate (bits per second) and wait for port to open
  Serial.begin(9600);
  while (!Serial) { ; }

  // init the RGB leds
  for (int i = 0; i < ELEMENTS(pins, int); i++) {
    int p = pins[i];
    pinMode(p, OUTPUT);
    digitalWrite(p, state[i]);
  }
}

void loop() {
  // waiting by a 'R' char to redefine leds values
  while (Serial.available()) {
    char incomingByte = (char)Serial.read();
    if (incomingByte == 'R') {
      state[0] = !state[0];
    } else if (incomingByte == 'G') {
      state[1] = !state[1];
    } else if (incomingByte == 'B') {
      state[2] = !state[2];
    }
  }

  // update pins
  for (int i = 0; i < ELEMENTS(pins, int); i++) {
    int p = pins[i];
    pinMode(p, OUTPUT);
    digitalWrite(p, state[i]);
  }
}



