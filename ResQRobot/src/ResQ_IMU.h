/*
  ResQ_IMU.h
  Thin wrapper around the Adafruit BNO055 9-DOF orientation sensor.
  Teams typically use the X axis (yaw) reading to make accurate turns.

  Requires "Adafruit BNO055" and "Adafruit Unified Sensor"
  (install both via Library Manager).
*/
#ifndef ResQ_IMU_h
#define ResQ_IMU_h

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Wire.h>

class ResQImu {
  public:
    // sensorId is an arbitrary ID used to tag events from this sensor.
    // address is the BNO055's I2C address (0x28 or 0x29 depending on wiring).
    ResQImu(int32_t sensorId = 55, uint8_t address = 0x28, TwoWire *wire = &Wire);

    // Initializes the sensor. Returns false if it isn't detected on the bus.
    bool begin();

    // Absolute orientation in degrees: x = yaw/heading, y = roll, z = pitch.
    void getOrientation(float &x, float &y, float &z);

    // Convenience accessor for just the heading (x axis), used for turns.
    float getHeading();

    // Calibration status of each subsystem, 0 (uncalibrated) to 3 (fully calibrated).
    void getCalibration(uint8_t &system, uint8_t &gyro, uint8_t &accel, uint8_t &mag);

    // True once the system status reports fully calibrated.
    bool isFullyCalibrated();

  private:
    Adafruit_BNO055 _bno;
};

#endif
