/*

    Example code for Adafruit_LSM9DS0 (accelerometer, gyroscope, magnetometer) sensor

*/

#include "codetacc-wearables/codetacc-wearables.h"

Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();

bool init = false;

int accelX;
int accelY;
int accelZ;
int magX;
int magY;
int magZ;
int gyroX;
int gyroY;
int gyroZ;

void setup() {
    if (lsm.begin()) {
        Particle.publish("Accelerometer found!");
        lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
        lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
        lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
        Particle.variable("accelX", accelX);
        Particle.variable("accelY", accelY);
        Particle.variable("accelZ", accelZ);
        Particle.variable("magX", magX);
        Particle.variable("magY", magY);
        Particle.variable("magZ", magZ);
        Particle.variable("gyroX", gyroX);
        Particle.variable("gyroY", gyroY);
        Particle.variable("gyroZ", gyroZ);
        init = true;
    } else {
        Particle.publish("Accelerometer could not be found.");
    }
}

void loop() {
    if (init) {
        lsm.read();
        accelX = (int)lsm.accelData.x;
        accelY = (int)lsm.accelData.y;
        accelZ = (int)lsm.accelData.z;
        magX = (int)lsm.magData.x;
        magY = (int)lsm.magData.y;
        magZ = (int)lsm.magData.z;
        gyroX = (int)lsm.gyroData.x;
        gyroY = (int)lsm.gyroData.y;
        gyroZ = (int)lsm.gyroData.z;

    }

    delay(500);
}


/*

    Example code for Adafruit_LSM9DS0 (accelerometer, gyroscope, magnetometer) sensor

*/

#include "codetacc-wearables/codetacc-wearables.h"

Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();

String accelReport = "";
String magReport = "";
String gyroReport = "";
bool init = false;

void setup() {
    if (lsm.begin()) {
        Particle.publish("Accelerometer found!");
        lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
        lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
        lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
        Particle.variable("Accel", accelReport);
        Particle.variable("Mag", magReport);
        Particle.variable("Gyro", gyroReport);
        init = true;
    } else {
        Particle.publish("Accelerometer could not be found.");
    }
}

void loop() {
    if (init) {
        lsm.read();
        int accelX = (int)lsm.accelData.x;
        int accelY = (int)lsm.accelData.y;
        int accelZ = (int)lsm.accelData.z;
        int magX = (int)lsm.magData.x;
        int magY = (int)lsm.magData.y;
        int magZ = (int)lsm.magData.z;
        int gyroX = (int)lsm.gyroData.x;
        int gyroY = (int)lsm.gyroData.y;
        int gyroZ = (int)lsm.gyroData.z;
        
        magReport = String::format("x: %n, y: %n, z: %n", magX, magY, magZ);
        gyroReport = String::format("x: %n, y: %n, z: %n", gyroX, gyroY, gyroZ);
        accelReport = String::format("x: %n, y: %n, z: %n", accelX, accelY, accelZ);
        
    }

    delay(500);
}


/*

    Example code for Adafruit_LSM9DS0 (accelerometer, gyroscope, magnetometer) sensor

*/

#include "codetacc-wearables/codetacc-wearables.h"

Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();

String accelReport = "";
String magReport = "";
String gyroReport = "";
bool init = false;

void setup() {
    if (lsm.begin()) {
        Particle.publish("Accelerometer found!");
        lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
        lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
        lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
        Particle.variable("Accel", accelReport);
        Particle.variable("Mag", magReport);
        Particle.variable("Gyro", gyroReport);
        init = true;
    } else {
        Particle.publish("Accelerometer could not be found.");
    }
}

void loop() {
    if (init) {
        lsm.read();
        int accelX = (int)lsm.accelData.x;
        int accelY = (int)lsm.accelData.y;
        int accelZ = (int)lsm.accelData.z;
        int magX = (int)lsm.magData.x;
        int magY = (int)lsm.magData.y;
        int magZ = (int)lsm.magData.z;
        int gyroX = (int)lsm.gyroData.x;
        int gyroY = (int)lsm.gyroData.y;
        int gyroZ = (int)lsm.gyroData.z;
        
        magReport = String::format("x: %n, y: %n, z: %n", magX, magY, magZ);
        gyroReport = String::format("x: %n, y: %n, z: %n", gyroX, gyroY, gyroZ);
        accelReport = String::format("x: %n, y: %n, z: %n", accelX, accelY, accelZ);
        
    }

    delay(500);
}
