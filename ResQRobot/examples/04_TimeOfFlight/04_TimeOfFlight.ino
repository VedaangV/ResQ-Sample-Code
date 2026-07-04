/*
  04_TimeOfFlight
  Reads distance in millimeters from the VL53L0X time-of-flight sensor.
  More precise than the HC-SR04 at short range - handy for wall
  alignment or detecting narrow gaps.
*/
#include <ResQRobot.h>

ResQTofSensor tof;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  if (!tof.begin()) {
    Serial.println("VL53L0X not found - check wiring!");
    while (1);
  }
}

void loop() {
  int distanceMm = tof.readDistanceMM();

  if (distanceMm < 0) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance (mm): ");
    Serial.println(distanceMm);
  }

  delay(100);
}
