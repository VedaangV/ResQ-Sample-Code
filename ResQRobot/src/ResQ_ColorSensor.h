/*
  ResQ_ColorSensor.h
  Thin wrapper around the Adafruit APDS9960 library for the color sensor
  used to detect floor tile colors (e.g. green tile / silver tile markers).

  Requires the "Adafruit APDS9960 Library" (install via Library Manager).
*/
#ifndef ResQ_ColorSensor_h
#define ResQ_ColorSensor_h

#include <Arduino.h>
#include <Adafruit_APDS9960.h>

class ResQColorSensor {
  public:
    ResQColorSensor();

    // Initializes the sensor over I2C. Returns false if it isn't detected.
    bool begin();

    // True once a fresh color reading is available.
    bool colorReady();

    // Reads raw red/green/blue/clear channel values. Only valid data if
    // colorReady() was true (or you don't mind occasionally-stale values).
    void readColor(uint16_t &r, uint16_t &g, uint16_t &b, uint16_t &c);

  private:
    Adafruit_APDS9960 _apds;
};

#endif
