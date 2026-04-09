const int POT_PIN = A0;
const int TOLERANCE = 5;
const unsigned int DEBOUNCE_TIME = 50;

int stable = 0;
unsigned int lastChangeTime = 0;
bool checking = false;


void setup() {
  Serial.begin(9600);
  stable = analogRead(POT_PIN);
}


void loop() {
  int reading = analogRead(POT_PIN);

  // se a leitura for diferente do valor estável (considerando a tolerancia)
  if (abs(reading - stable) > TOLERANCE) {
    // reset debounce timer
    if (checking == false) {
      Serial.println("reset");
      lastChangeTime = millis();
      checking = true;
    }
  } else {
    checking = false;
  }

  // se a leitura ficar diferente tempo suficiente
  if (checking == true && millis() - lastChangeTime > DEBOUNCE_TIME) {
    // atualiza o valor
    if (abs(reading - stable) > TOLERANCE) {
      stable = reading;
      checking = false;
    }
  }

  // envia o valor
  // Serial.println(reading);
  Serial.println((String) "p:" + stable);

  delay(5);
}
