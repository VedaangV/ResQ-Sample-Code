#include "ResQ_ToF.h"

ResQTofSensor::ResQTofSensor() {
}

bool ResQTofSensor::begin() {
  return _lox.begin();
}

int ResQTofSensor::readDistanceMM() {
  VL53L0X_RangingMeasurementData_t measure;
  _lox.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) { // 4 = phase failure, i.e. out of range
    return measure.RangeMilliMeter;
  }
  return -1;
}
