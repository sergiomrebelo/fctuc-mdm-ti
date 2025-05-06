#include <Servo.h>

Servo servo; // my servo
// twelve servo objects can be created on most boards
int pos = 0; // servo position

void setup() {
  servo.attach(9);
  servo.write(90);
}

void loop() {
  // sweep the servo from 0 to 180 degrees in steps of 1
  for (pos = 0; pos <= 180; pos += 1) { 
    // tell servo to go to position in variable 'pos'
    servo.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15);  // Wait for 15 millisecond(s)
  }
}
