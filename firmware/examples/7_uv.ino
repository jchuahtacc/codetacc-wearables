#include "codetacc-wearables/codetacc-wearables.h"

Adafruit_SI1145 uv = Adafruit_SI1145();

bool init = false;
double ultraviolet;
int infrared;
int visible;

void setup() {
  Serial.begin(9600);
  
  Serial.println("Adafruit SI1145 test");
  
  if (uv.begin()) {
      Particle.publish("Ultraviolet sensor found!");
      Particle.variable("uv", ultraviolet);
      Particle.variable("ir", infrared);
      Particle.variable("vis", visible);
      init = true;
  } else {
      Particle.publish("Ultraviolet sensor couldn't be found!");
  }

}

void loop() {
    if (init) {
        ultraviolet = uv.readUV() / 100.0;
        infrared = uv.readIR();
        visible = uv.readVisible();
    }
    delay(1000);
}
