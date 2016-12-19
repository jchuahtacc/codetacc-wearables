#include "application.h"

#define BUTTON      2
#define LED         7
volatile boolean signal = false;

void isr() {
      signal = true;
}

void setup() {
      pinMode(LED, OUTPUT);
        pinMode(BUTTON, INPUT);
          attachInterrupt(BUTTON, isr, RISING);
}

void loop() {
      digitalWrite(LED, signal);
}
