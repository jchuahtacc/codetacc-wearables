#include "application.h"
#include "codetacc-wearables/codetacc-wearables.h"

#define SENSOR A0

double voltage = 0;

void setup() {
    Particle.variable("voltage", voltage);

    pinMode(SENSOR, INPUT);
}

void loop() {
    int analogValue = analogRead(SENSOR);
    voltage = analogValue * 3.3 / 4095;
    delay(1000);
}
