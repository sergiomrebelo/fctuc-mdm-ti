const long BUTTON_PIN = 3;
const long DEBOUNCE_DELAY = 50;

long lastButtonState = LOW;
long buttonState = LOW;
long ledState = LOW;

unsigned long lastDebounceTime = 0;  // unsigned to prevents issues when millis() overflows
long randomDelay = 0, baseLEDTime = millis();

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int reading = !digitalRead(BUTTON_PIN);  // inverted because of INPUT_PULLUP

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }


  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        // the button should not work in 1 of 10 attempts
        if (random(11) != 1) {
          ledState = !ledState;
          randomDelay = millis();
          baseLEDTime = random(250, 2000);
        } else {
          Serial.println("The button not work this time!");
        }
      }
    }
  }
  if ((millis() - baseLEDTime) > randomDelay) {
    digitalWrite(LED_BUILTIN, ledState);
  }
  lastButtonState = reading;
}
