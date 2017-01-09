#include "application.h"
#include "codetacc-robotics/codetacc-robotics.h"

#define BUTTON      2
#define LED         7

volatile boolean signal = false;

void isr() {
    signal = true;
}

void doWork() {
}

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);
    attachInterrupt(BUTTON, isr, RISING);
}

void loop() {
    if (signal) {
        doWork();
        signal = false;
    }
}
