/**
* Tecnologias de Interface, 2026
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Home Challenge 1
* Smart Night Light 
* Build a smart night light using an Arduino, an LDR (connected to pin A0), and an LED connected to pin 12.
* The LED should automatically turn on when the ambient light decreases and turn off when there is more light.
* You should use a push button (connected to pin 4) to completely turn the night light on and off.
* The circuit should include a potentiometer (connected to pin A1), which will be used to adjust the light threshold at which the LED turns on.
* The range of values produced by adjusting the potentiometer should vary between 64 (potentiometer at minimum) and 1023 (potentiometer at maximum). (Suggestion: check the syntax of the map() function.)
* 
* @authors: Sérgio M. Rebelo and Tiago Cruz
* @since:   12–04–2023      
*/

const int LED_PIN = 12;
const int BT_PIN = 4;
const int LDR_PIN = A0;
const int POT_PIN = A1;

bool on = false, pBtState = HIGH;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BT_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // turn on/off the light
  int btState = digitalRead(BT_PIN);

  if (pBtState == HIGH && btState == LOW) {
    on = !on;
    if (!on) {
      digitalWrite(LED_PIN, LOW);
    }
    delay(50);  // fake debounce
  }

  pBtState = btState;

  if (on == true) {
    int lightValue = analogRead(LDR_PIN);
    int potValue = analogRead(POT_PIN);
    int threshold = map(potValue, 0, 1023, 64, 1023);

    Serial.println("l=" + String(lightValue));
    Serial.println("p=" + String(potValue));
    Serial.println("t=" + String(threshold));

    bool lightOn = LOW;
    // turn on where the light is not enought
    if (lightValue < threshold) {
      lightOn = HIGH;
    }

    digitalWrite(LED_PIN, lightOn);
  }
}
