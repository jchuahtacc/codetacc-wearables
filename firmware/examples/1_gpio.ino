#include "application.h"
#include "codetacc-wearables/codetacc-wearables.h"

int flash(String parameters = "") {
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(7, LOW);
    delay(1000);
}

void setup() {
    pinMode(7, OUTPUT);
}

void loop() {
    flash();
}
