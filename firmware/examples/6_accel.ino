/*

    Example code for Adafruit_LSM9DS0 (accelerometer, gyroscope, magnetometer) sensor

*/

#include "Adafruit_LSM9DS0/Adafruit_LSM9DS0.h"
#include "Adafruit_LSM9DS0/Adafruit_Sensor.h"  // not used in this demo but required!

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
