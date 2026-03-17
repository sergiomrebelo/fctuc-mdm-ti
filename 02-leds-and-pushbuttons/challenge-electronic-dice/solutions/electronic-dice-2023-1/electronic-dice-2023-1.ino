/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Challenge #2
* Electronic dice
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   16–03–2023      
*/

// sizeof returns the number of bytes in an array
// if you want the length of the array, divide the number of bytes in the array by the number of bytes in the data type.
#define ELEMENTS(x, type) (sizeof(x) / sizeof(type))

const int BT_PIN = 9;                          // pushbutton pin
const int LED_PINS[6] = { 2, 3, 4, 5, 6, 7 };  // led pin

int btState;                 // variable for reading the pushbutton status
int generating = HIGH;       // in the generation of random number
int previousLedState = LOW;  // previous state of the led

// time variables
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the bounce time;

// random number
int r = 0;

void setup() {
  //configure pin 9 as an input and enable the internal pull-up resistor
  pinMode(BT_PIN, INPUT_PULLUP);

  // init the leds pin
  for (int i = 0; i < ELEMENTS(LED_PINS, int); i++) {
    int p = LED_PINS[i];
    pinMode(p, OUTPUT);
    digitalWrite(p, HIGH);
  }

  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
}

void loop() {
  // read the state of pushbutton pin
  int reading = digitalRead(BT_PIN);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you are waited
  // long enough since the last press to ignore any noise:.

  // If the switch changed, due to noise or pressing:
  if (reading != previousLedState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != btState) {
      btState = reading;

      // only toggle the LED if the new button state is HIGH
      if (btState == HIGH) {
        generating = !generating;
      }
    }
  }

  if (generating) {
    // generate a new random number
    r = (int) random(7);

    // activate the leds
    for (int i = 0; i < ELEMENTS(LED_PINS, int); i++) {
      int p = LED_PINS[i];
      if (i < r) {
        digitalWrite(p, HIGH);
      } else {
        digitalWrite(p, LOW);
      }
    }
    // print the values
    Serial.println((String)"number:" + r);
    delay(150);
  }

  // save the reading.
  previousLedState = reading;
}
