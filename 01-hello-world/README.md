# Hello Word (Arduino Setup, Week 1)

## 1. Install the Arduino IDE
1. Go to: https://www.arduino.cc/en/Main/Software
2. Download the latest Arduino IDE for your operating system.
3. Install it.

## 2. Connect Your Arduino
1. Plug the USB cable into your computer and your Arduino board.
2. Check if it is detected:
   - **Windows:** Device Manager → Ports (COM & LPT)
   - **macOS:** System Information → USB
3. Install drivers if needed:
   - Windows guide: http://arduino.cc/en/guide/windows
   - macOS guide: http://arduino.cc/en/guide/macOSX
   - FTDI drivers (older boards): http://www.ftdichip.com/Drivers/VCP.htm

## 3. Configure the IDE
1. Open the **Arduino IDE**.
2. Go to **Tools → Board** and select your board.
3. Go to **Tools → Port** and select the correct USB/serial port.

## 4. Test With Example Code
1. Go to **File → Examples → Basics → Blink**.
2. Click **Verify** to compile the sketch.
3. Click **Upload** to send it to the board.
4. The onboard LED should start blinking.
