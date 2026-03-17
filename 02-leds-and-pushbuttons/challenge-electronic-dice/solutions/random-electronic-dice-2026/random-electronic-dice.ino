const long LED_PIN = 13;
const long BT_PIN = 2;

long ledState = HIGH;
long btState;
long previousBtState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

long ledTimer = 0;
long randomDelay = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BT_PIN, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  int reading = !digitalRead(BT_PIN);

  if (reading != previousBtState) {
    lastDebounceTime = millis();
  }

  if ((millis() - previousBtState) > debounceDelay) {
    if (reading != btState) {
      btState = reading;

      if (btState == HIGH) {
        Serial.println(random(11));
        if (random(11) != 1) {
          ledState = !ledState;
          ledTimer = millis();
          randomDelay = random(250, 2001);
        }
      }
    }
  }

  if ((millis() - ledTimer) > randomDelay) {
    digitalWrite(LED_PIN, ledState);
  }
  previousBtState = reading;
}
