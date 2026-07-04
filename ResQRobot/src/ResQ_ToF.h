/*
  ResQ_ToF.h
  Thin wrapper around the Adafruit VL53L0X time-of-flight distance sensor.
  More precise than the HC-SR04 at short range, commonly used for wall
  alignment or narrow obstacle/gap detection.

  Requires "Adafruit VL53L0X" (install via Library Manager).
*/
#ifndef ResQ_ToF_h
#define ResQ_ToF_h

#include <Arduino.h>
#include <Adafruit_VL53L0X.h>

class ResQTofSensor {
  public:
    ResQTofSensor();

    // Initializes the sensor over I2C. Returns false if it isn't detected.
    bool begin();

    // Returns distance in millimeters, or -1 if the reading is out of range.
    int readDistanceMM();

  private:
    Adafruit_VL53L0X _lox;
};

#endif
