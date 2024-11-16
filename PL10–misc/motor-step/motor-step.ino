#include <Stepper.h>

const int stepsPerRevolution = 2038; 

Stepper myStepper(stepsPerRevolution, 25, 26, 27, 14);  // IN1, IN2, IN3, IN4

void setup() {
  // Set the speed of the motor in RPM (revolutions per minute)
  myStepper.setSpeed(5);  // Reduced speed for better debugging
  Serial.begin(9600);
  Serial.println("Stepper Test Start");
}

void loop() {
  Serial.println("Stepping forward...");
  myStepper.step(stepsPerRevolution / 2);  // Half revolution forward
  delay(1000);  // Wait for 1 second

  Serial.println("Stepping backward...");
  myStepper.step(-stepsPerRevolution / 2);  // Half revolution backward
  delay(1000);  // Wait for 1 second

  Serial.println("Completed full cycle");
}
