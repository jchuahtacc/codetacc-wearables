/*

    Sample code for Adafruit_TSL2561 Lux (light level) Sensor

*/
#include "codetacc-wearables/codetacc-wearables.h"
  
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

double lux;
bool init = false;

void setup(void) {
    if(tsl.begin()) {
        Particle.publish("Lux sensor found!");
        tsl.enableAutoRange(true);
        tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);
        Particle.variable("lux", lux); 
        init = true;
    } else {
        Particle.publish("Lux sensor could not be found!");
    }
}

void loop(void) {  
    if (init) {
        // Get a new sensor event
        sensors_event_t event;
        tsl.getEvent(&event);
        if (event.light) {
            lux = event.light;
        }
    }
    delay(250);
}
