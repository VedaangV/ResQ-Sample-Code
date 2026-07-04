#include "ResQ_ColorSensor.h"

ResQColorSensor::ResQColorSensor() {
}

bool ResQColorSensor::begin() {
  if (!_apds.begin()) {
    return false;
  }
  _apds.enableColor(true);
  return true;
}

bool ResQColorSensor::colorReady() {
  return _apds.colorDataReady();
}

void ResQColorSensor::readColor(uint16_t &r, uint16_t &g, uint16_t &b, uint16_t &c) {
  _apds.getColorData(&r, &g, &b, &c);
}
