/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 3
* Digital Dice (6 led) with a pull-up pushbutton (with debouncing)
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   24–02–2023      
*/
int BT_PIN = 2;
int LED_PINS[] = { 4, 5, 6, 7, 8, 9 };

int btState = 0;             // variable for reading the pushbutton status
int ledState = HIGH;         // current state of the led
int previousLedState = LOW;  // previous state of the led

// time variables
long lastDebounceTime = 0;   // the last time the output pin was toggled
long debounceTimeDelay = 0;  // the bounce time;

// dice variables
int r = 0;
bool running = false;

void setup() {
  // DEBUG: open the serial port at 9600 bps:
  Serial.begin(9600);

  // init bt pin
  pinMode(BT_PIN, INPUT_PULLUP);

  // init led pins
  for (int pin : LED_PINS) {
    pinMode(pin, OUTPUT);
  }
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
    // when push the button
    if (btState != reading && btState == HIGH) {
      running = !running;
    }
    // whatever the reading is at, it is been there for longer
    // than the debounce delay, so take it as the actual current state
    btState = reading;
  }
  int c = 0;
  for (int pin : LED_PINS) {
    if (c <= r) {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
    c++;
  }

  if (running) {
    // start generate random number
    r = (int) random(6.4);
    delay(150);
    // DEBUG
    // Serial.print("r: ");
    // Serial.println(r);
  }

  // save the reading.
  previousLedState = reading;
}
