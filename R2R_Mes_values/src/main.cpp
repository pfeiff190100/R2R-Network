#include <Arduino.h>

#define D0 2
#define D1 3
#define D2 4
#define D3 5

void setup() {
  Serial.begin(9600);

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
}

void loop() {
  uint8_t states[2] = {LOW, HIGH};

  for (uint8_t state_D3 : states){
    for (uint8_t state_D2 : states){
      for (uint8_t state_D1 : states){
        for (uint8_t state_D0 : states){
          // write the PIN states to the pins
          // these are either HIGH or LOW
          digitalWrite(D0, state_D0);
          digitalWrite(D1, state_D1);
          digitalWrite(D2, state_D2);
          digitalWrite(D3, state_D3);

          delay(50);
        }
      }
    }
  }
}