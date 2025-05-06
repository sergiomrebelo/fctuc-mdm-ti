# Servo Motor with Arduino: Overview and Connection Guide

## What is a Servo Motor?

A **servo motor** is a rotary actuator that allows for precise control of angular position. The **SM-S2309S** is a small, analog servo motor commonly used in robotics and DIY electronics projects. It receives a control signal (PWM) to set its shaft position between 0° and 180°.

Servo motors are ideal for:
- Controlling robotic arms or joints
- Moving sensors or cameras
- Automated mechanisms (e.g., levers, gates)
- Projects requiring precise angular motion

## SM-S2309S Motor Specifications

- Operating Voltage: 4.8V – 6.0V
- Control Signal: PWM
- Rotation Range: ~0° to 180°
- Torque: ~2.5kg·cm @ 4.8V
- Weight: ~14g

---

## Basic Servo Control

This example shows how to connect the SM-S2309S servo to an Arduino and sweep the arm between 0° and 180° continuously.

### Hardware Required
- Arduino Uno (or similar)
- SM-S2309S servo motor
- External 5V power supply (recommended)
- Jumper wires
- Breadboard

### Wiring Diagram

![Basic Servo Connection](scheme-basic.png)

| Servo Wire | Connect To          |
|------------|---------------------|
| Servo Signal (White/Orange/Yellow) | Arduino Pin 9       |
| Servo VCC (Red)                    | 5V (external preferred) |
| Servo GND (Brown/Black)            | GND                  |

> ℹ️ **Important:** Always connect the ground of the external power supply to the Arduino's GND.

The sample code for this setup is located in the [`src-servo-basic`](./src-servo-basic) folder.

---

## Interactive Servo Control with Potentiometer

In this setup, a potentiometer is used to control the servo position interactively by varying its rotation from 0° to 180° based on the potentiometer reading.

### Hardware Required
- Arduino Uno
- SM-S2309S servo motor
- Potentiometer (10kΩ)
- Jumper wires
- Breadboard
- External 5V power supply (recommended)

Wiring Diagram

### Wiring Diagram

![Interactive Servo Connection](scheme-interative.png)

| Component                          | Connect To              |
|------------------------------------|-------------------------|
| Servo Signal (White/Orange/Yellow) | Arduino Pin 9       |
| Servo VCC (Red)                    | 5V (external preferred) |
| Servo GND (Brown/Black)            | GND                  |
| Potentiometer VCC                  | 5V                      |
| Potentiometer GND                  | GND                     |
| Potentiometer Output (Middle Pin)  | Arduino A0      |

The source code for this interactive example is located in the [`src-servo-interative`](./src-servo-interative) folder.


### Notes, Tips, and Safety Precautions
- Always connect GNDs together when using an external power supply.
- Avoid powering servos directly from the Arduino's 5V pin when under load.
- Use the [Servo](https://docs.arduino.cc/learn/electronics/servo-motors/) library included with the Arduino IDE.
- Add a capacitor (e.g., 100μF) across the power and ground near the servo for stability.
