# NeoPixel with Arduino: Overview and Connection Guide

## What is NeoPixel?

**NeoPixel** refers to a family of individually addressable RGB LEDs developed by Adafruit. These LEDs allow you to control the color and brightness of each LED in a strip or matrix, offering a wide variety of possibilities for lighting effects in your Arduino projects. NeoPixels are popular for use in lighting displays, decorative lighting, wearables, and more.

NeoPixels are controlled by sending a data signal that determines the color and brightness for each LED in a chain. The signal is transferred via a single wire, which makes it simple to connect multiple NeoPixels together.

## NeoPixel Components

A typical **NeoPixel strip** or matrix for Arduino includes:
- A series of individually addressable RGB LEDs
- A controller chip (usually WS2812 or similar)
- Power and ground connections
- Data input pin (usually one wire for communication)

### Key Features of NeoPixel LEDs:
- **Addressable**: Each LED can be controlled individually.
- **RGB Color Mixing**: Each LED has red, green, and blue diodes to mix colors.
- **Low Power Consumption**: Each LED only draws power based on its color and brightness.
- **Chaining**: You can chain multiple NeoPixels to create long strips or complex arrays.

## How to Connect NeoPixel to an Arduino

### Hardware Required
- Arduino (Uno, Mega, Nano, etc.)
- NeoPixel strip or matrix
- Jumper wires
- Power supply for the NeoPixel strip (check voltage ratings, usually 5V)
- Capacitor (1000µF, 6.3V or higher) for power smoothing
- Resistor (330Ω) for the data line

### Basic Wiring Diagram

![NeoPixel Connection](scheme.png)

| NeoPixel Pin | Connect To                      |
|--------------|---------------------------------|
| VCC          | 5V pin on Arduino               |
| GND          | GND pin on Arduino              |
| Data Input   | Arduino digital pin (e.g., D6)  |

**NOTE**: If you're using a long strip of NeoPixels, you may need to power the strip externally (e.g., using a 5V power supply) and connect the ground of both the Arduino and the power supply to ensure proper operation.

### Wiring Notes:
- Use a **330Ω resistor** in series with the data input to prevent signal degradation.
- Use a **1000µF capacitor** across the VCC and GND of the NeoPixel strip to smooth out power fluctuations.
- Make sure the power supply you use can handle the total current required by the entire NeoPixel strip.

The NeoPixel control code is available in the [src-neopixel-basic](./src-neopixel-basic) and [src-neopixel-folder](./src-neopixel-folder) folders.

### Notes, Tips, and Best Practices:
- **Power Requirements**: NeoPixels can draw a lot of current, especially when many LEDs are lit up brightly. For large strips, use an external power supply capable of delivering sufficient current (e.g., 5V at 2A for a 60-LED strip).
- **Resistor for Data Pin**: Always use a **330Ω resistor** between the data pin and the NeoPixel input to prevent damaging the first LED.
- **Capacitor**: Adding a **1000µF capacitor** between VCC and GND of the NeoPixel strip will help prevent power spikes when the strip is powered on.
- **Level Shifting**: If you are using a 3.3V Arduino (e.g., Arduino Due), you may need a level shifter for the data line to ensure reliable communication with the NeoPixels.

### Troubleshooting:
- If the LEDs are flickering or not responding, double-check the power connections and ensure your power supply can handle the current requirements.
- Ensure the data line is correctly connected and the correct Arduino pin is specified in your code.

With this guide, you should be able to get started with NeoPixels and Arduino for your lighting projects!
