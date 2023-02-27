/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 3
* Control led with a pull-up pushbutton (with debouncing)
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   24–02–2023      
*/

const int BT_PIN = 2;    // pushbutton pin

int btState = 0;             // variable for reading the pushbutton status
int ledState = HIGH;         // current state of the led
int previousLedState = LOW;  // previous state of the led

// time variables
long lastDebounceTime = 0;   // the last time the output pin was toggled
long debounceTimeDelay = 100;  // the bounce time;


void setup() {
  // init pins
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BT_PIN, INPUT_PULLUP);

  digitalWrite(LED_BUILTIN, ledState);
}

void loop() {
  // read the state of pushbutton pin
  int reading = digitalRead(BT_PIN);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you are waited
  // long enough since the last press to ignore any noise:.

  // If the switch changed, due to noise or pressing:
  if (reading != lastDebounceTime) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceTimeDelay) {
    // whatever the reading is at, it is been there for longer
    // than the debounce delay, so take it as the actual current state
    btState = reading;

    if (btState == HIGH) {
        ledState = !ledState;
      }
  }

  // set the LED using the state of the button
  digitalWrite(LED_BUILTIN, ledState);

  // save the reading. 
  previousLedState = reading;
}
