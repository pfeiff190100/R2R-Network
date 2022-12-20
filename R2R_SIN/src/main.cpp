#include <Arduino.h>

int x = 0;

// setup function for initializing serial communication
// and setting the direction of portB to output
void setup() {
  Serial.begin(9600);
  DDRB = B11111111; // set all PORTS to on
}

// function to generate a 4-bit sinus wave
double FOUR_BIT_SIN() {
  return (7.5 * sin(x * 0.3) + 7.5);
}

// function to generate a 6-bit sinus wave
double SIX_BIT_SIN() {
  return (31.5 * sin(0.1*x) + 31.5);
}

// function to count up and down from 0 to 15 and write it to
// the Ports, which will generate a wave which is no sin, a linear wave
void NO_SIN_COUNT() {
  for (int i = 0; i <= 15; i++) {
    PORTB = i;
    delay(10);
  }
  for (int i = 15; i >= 0; i--) {
    PORTB = i;
    delay(10);
  }
}

// main loop function for writing the value of the 6-bit / 4-bit
// sinusoidal wave to portB and reading the value of analog
void loop() {
  //NO_SIN_COUNT();
  PORTB = SIX_BIT_SIN();
  x++;
  delay(10);
  Serial.println(analogRead(A0)); // reads out the output of the R2R network, could be used to monitor the signal
}
