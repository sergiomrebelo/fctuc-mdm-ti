#include <Servo.h>

int pos = 0 ; // potenciometer position
int angle = 0 ;
Servo servo;

void setup()
{
  servo.attach(5);
  Serial.begin(9600);
}

void loop()
{
  pos = analogRead(A3) ;
  angle = map (pos, 0, 1023, 0, 180);
  servo.write(angle);
  Serial.println("potenciometer value ="+(String)pos);
  Serial.println("servo angle ="+(String)angle+"degres");
  Serial.println("");
  delay(100);
}

