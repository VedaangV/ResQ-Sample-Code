#include "ResQ_IMU.h"

ResQImu::ResQImu(int32_t sensorId, uint8_t address, TwoWire *wire)
  : _bno(sensorId, address, wire) {
}

bool ResQImu::begin() {
  if (!_bno.begin()) {
    return false;
  }
  delay(1000);
  _bno.setExtCrystalUse(true);
  return true;
}

void ResQImu::getOrientation(float &x, float &y, float &z) {
  sensors_event_t event;
  _bno.getEvent(&event);
  x = event.orientation.x;
  y = event.orientation.y;
  z = event.orientation.z;
}

float ResQImu::getHeading() {
  float x, y, z;
  getOrientation(x, y, z);
  return x;
}

void ResQImu::getCalibration(uint8_t &system, uint8_t &gyro, uint8_t &accel, uint8_t &mag) {
  _bno.getCalibration(&system, &gyro, &accel, &mag);
}

bool ResQImu::isFullyCalibrated() {
  uint8_t system, gyro, accel, mag;
  getCalibration(system, gyro, accel, mag);
  return system == 3 && gyro == 3 && accel == 3 && mag == 3;
}
