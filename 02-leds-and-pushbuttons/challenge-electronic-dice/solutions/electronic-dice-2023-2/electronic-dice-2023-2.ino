#define BUTTON_PIN 13
bool flag=false;
int gen_rand=0;
long lastclick;
int interval=50;


void setup() {
  for (int i=2;i<=8;i++)
      pinMode(i, OUTPUT);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  Serial.begin(9600);
  lastclick=millis();
}
void loop() {
  
  if (digitalRead(BUTTON_PIN)==HIGH) {
     
    if (millis()-lastclick >interval)
         flag=!flag;
     
    lastclick=millis();
  }
  if (flag) {
    gen_rand=random(1,7);
    Serial.println(gen_rand);
      
    for (int i=2;i<8;i++)    
        digitalWrite(i, i<(2+gen_rand));
    
    delay(200);
  } else if (gen_rand!=0) {
    Serial.println("Valor escolhido:"+String(gen_rand));
    gen_rand=0;
  }
  
}
