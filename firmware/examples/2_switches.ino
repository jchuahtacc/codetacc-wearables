#include "application.h"

#define BUTTON      2
#define LED         7

volatile boolean signal = false;

void isr() {
    signal = true;
}

void doWork() {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
}

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT_PULLDOWN);
    attachInterrupt(BUTTON, isr, RISING);
}

void loop() {
    if (signal) {
        noInterrupts();
        signal = false;
        doWork();
        interrupts();
    }
}
