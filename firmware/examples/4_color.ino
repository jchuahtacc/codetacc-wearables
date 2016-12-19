/*

Sample code for Adafruit_TCS34725 Color Sensor

*/

#include "codetacc-wearables/codetacc-wearables.h"
#include <math.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

float r, g, b;
bool init = false;

void setup() {
    if (tcs.begin()) {
        Particle.publish("Color sensor found!");
        Particle.variable("red", r);
        Particle.varaible("green", g);
        Particle.variable("blue", b);
        init = true;
    } else {
        Particle.publish("Color sensor could not be found.");
    }
}

void loop() {
    if (init) {
        uint16_t clear, red, green, blue;

        tcs.setInterrupt(false);      // turn on LED
        
        delay(60);  // takes 50ms to read 
          
        tcs.getRawData(&red, &green, &blue, &clear);
        tcs.setInterrupt(true);  // turn off LED
        
        // Figure out some basic hex code for visualization
        uint32_t sum = clear;
        
        // Compute the actual red, green and blue values
        r = red; r /= sum;
        g = green; g /= sum;
        b = blue; b /= sum;
        r *= 256; g *= 256; b *= 256;
    }
        
    delay(1000);
}
