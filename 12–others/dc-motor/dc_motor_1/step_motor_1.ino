// Define motor control pins for Motor 1 (A side of DRV8833)
const int motorA1Pin = 33;  // Connect to A1 on DRV8833
const int motorA2Pin = 32;  // Connect to A2 on DRV8833

// Define motor control pins for Motor 2 (B side of DRV8833)
const int motorB1Pin = 26;  // Connect to B1 on DRV8833
const int motorB2Pin = 25;  // Connect to B2 on DRV8833

const int stbyPin = 33;  // Connect to STBY on DRV8833 (optional)

void setup() {
  // Initialize motor control pins as outputs
  pinMode(motorA1Pin, OUTPUT);
  pinMode(motorA2Pin, OUTPUT);
  pinMode(motorB1Pin, OUTPUT);
  pinMode(motorB2Pin, OUTPUT);
  
  // Initialize standby pin
  pinMode(stbyPin, OUTPUT);
  digitalWrite(stbyPin, HIGH);  // Keep the motor driver active
}

void loop() {
  // Example sequence to control the motors

  // Move Motor 1 forward and Motor 2 backward
  moveMotor1Forward();
  moveMotor2Backward();
  delay(2000);  // Run motors for 2 seconds

  // Stop both motors
  stopMotors();
  delay(1000);  // Stop for 1 second

  // Move Motor 1 backward and Motor 2 forward
  moveMotor1Backward();
  moveMotor2Forward();
  delay(2000);  // Run motors for 2 seconds

  // Stop both motors
  stopMotors();
  delay(1000);  // Stop for 1 second
}

// Function to move Motor 1 forward
void moveMotor1Forward() {
  digitalWrite(motorA1Pin, HIGH);
  digitalWrite(motorA2Pin, LOW);
}

// Function to move Motor 1 backward
void moveMotor1Backward() {
  digitalWrite(motorA1Pin, LOW);
  digitalWrite(motorA2Pin, HIGH);
}

// Function to move Motor 2 forward
void moveMotor2Forward() {
  digitalWrite(motorB1Pin, HIGH);
  digitalWrite(motorB2Pin, LOW);
}

// Function to move Motor 2 backward
void moveMotor2Backward() {
  digitalWrite(motorB1Pin, LOW);
  digitalWrite(motorB2Pin, HIGH);
}

// Function to stop both motors
void stopMotors() {
  digitalWrite(motorA1Pin, LOW);
  digitalWrite(motorA2Pin, LOW);
  digitalWrite(motorB1Pin, LOW);
  digitalWrite(motorB2Pin, LOW);
}
