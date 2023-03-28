/**
* Tecnologias de Interface, Winter 2023
* Universidade de Coimbra
* MSc in Design and Multimedia
*
* Week 7
* Thermistor
* 
* @authors: Sérgio M. Rebelo, Ana Cláudia Rodrigues, and Tiago Cruz
* @since:   16–03–2023      
* @basedon: https://learn.adafruit.com/thermistor/using-a-thermistor
*/

// which analog pin to connect
#define THERMISTORPIN A0
// resistance at 25 degrees C
#define THERMISTORNOMINAL 10000
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25
// how many samples to take and average,
// more takes longer but is more 'smooth'
#define NUMSAMPLES 5
// The beta coefficient of the thermistor // (usually 3000-4000)
#define BCOEFFICIENT 3950
// the value of the 'other' resistor
#define SERIESRESISTOR 10000

int samples[NUMSAMPLES];

void setup() {
  Serial.begin(9600);
  // analogReference(EXTERNAL);
}


void loop() {
  uint8_t i;
  float average;

  // take N samples in a row, with a slight delay
  for (i = 0; i < NUMSAMPLES; i++) {
    samples[i] = analogRead(THERMISTORPIN);
    delay(10);
  }

  // average all the samples out
  average = 0;
  for (i = 0; i < NUMSAMPLES; i++) {
    average += samples[i];
  }
  average /= NUMSAMPLES;

  Serial.print("Average analog reading ");
  Serial.println(average);

  // convert the value to resistance
  average = 1023 / average - 1;
  average = SERIESRESISTOR / average;

  Serial.print("Thermistor resistance ");
  Serial.println(average);

  float steinhart;
  // (R/Ro)
  steinhart = average / THERMISTORNOMINAL;
  // ln(R/Ro)
  steinhart = log(steinhart);
  // 1/B * ln(R/Ro)
  steinhart /= BCOEFFICIENT;
  // + (1/To)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15);
  // Invert
  steinhart = 1.0 / steinhart;
  // convert to C
  steinhart -= 273.15;
  Serial.print("Temperature ");
  Serial.print(steinhart);
  Serial.println(" *C");

  delay(1000);
}
