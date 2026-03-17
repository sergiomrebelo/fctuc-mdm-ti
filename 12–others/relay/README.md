# Relay with Arduino: Overview and Connection Guide

## What is a Relay?

A **relay** is an electromechanical switch that allows you to control a high-voltage or high-current device (like a lamp or motor) using a low-voltage signal from a microcontroller such as an **Arduino**. It works by using an electromagnet to physically open or close a circuit, isolating the Arduino from potentially dangerous voltage levels.

Relays are often used in home automation, robotics, and embedded systems to control:
- AC appliances (lamps, fans)
- DC motors
- Heating elements
- Pumps, etc.

## Relay Module Components

A typical relay module for Arduino includes:
- The relay itself (usually rated 5V or 12V)
- A transistor to drive the relay coil
- A flyback diode to protect against voltage spikes
- An optocoupler (optional, for isolation)
- Indicator LED
- Screw terminals or pin headers for connecting devices

## How to Connect a Relay to an Arduino

### Hardware Required
- Arduino (Uno, Mega, Nano, etc.)
- Relay module (5V)
- Jumper wires
- Load device (e.g., light bulb or small AC appliance)
- Power source for the load (e.g., AC 220V or DC 12V, **handle with care**)

### Wiring Diagram

| Relay Pin | Connect To                      |
|-----------|---------------------------------|
| VCC       | Arduino 5V                      |
| GND       | Arduino GND                     |
| IN        | Arduino Digital Pin (e.g., D7)  |
| NO        | Device's live wire (Normally Open) |
| COM       | Live from power source          |
| NC        | (Optional, Normally Closed)     |

**NOTE**: When the relay is activated (IN = LOW or HIGH depending on the relay), the connection between COM and NO is closed.

The relay control code is available in the [`src-relay`](./src-relay) folder:

### Notes, Tips, and Safety Precautions
- DO NOT touch the relay module or wires when connected to high voltage.
- Use a protective case or relay module with isolation if switching AC devices.
- Ensure your relay’s voltage and current ratings match the load you are controlling.
- Double-check connections before powering on.