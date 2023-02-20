# Arduino & Friends: Going Further (Week 3)

Arduino controls LEDs based on the state of a pushbutton (pull-up). 

<img src="scheme.png"  alt="Circuit assembly used on this PL class" width="60%" height="auto">

#### Required Material
- Arduino Uno (or similar)
- six LEDs
- solderless breadboard
- six 220Ω resistor
- one pushbutton
- jumpers

## Exercice
The LED will turn OFF while you have the finger on the button. 

1. Connecting a pushbutton to the Arduino (pull-up, see [Week3_Pushbutton_pullup](https://github.com/sergiomrebelo/fctuc-mdm-ti/tree/main/PL3-Pushbutton-2/Week3_Pushbutton_pullup))

## Challenge
Connect a pushbutton (pull-up) and six LEDs (using 220 Ohm resistors) to six distinct digital pins in the Arduino. Write a program that simulates an electronic dice and displays the result through LEDS. You can use the [random()](https://www.arduino.cc/reference/en/language/functions/random-numbers/random/) function. 

#### Dice Rules
- When you press the button, the system will start printing a series of random numbers, between 1 and 6. 
- When you press the button again, the run will stop and the last generated number will be displayed. If you press the button, the generator will restart. You should place a delay of 150ms between each generation of random numbers.
- The number of LEDS on Mode HIGH shall correspond to the number rolled in the dice. 
