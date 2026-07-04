/*
  ResQ_Ultrasonic.h
  Driver for the HC-SR04 ultrasonic distance sensor. Teams typically use
  this to detect walls/obstacles ahead of the robot.
*/
#ifndef ResQ_Ultrasonic_h
#define ResQ_Ultrasonic_h

#include <Arduino.h>

class ResQUltrasonic {
  public:
    // timeoutUs bounds how long to wait for the echo before giving up
    // (30000us ~= 5m range, which is more than enough for this sensor).
    ResQUltrasonic(uint8_t trigPin, uint8_t echoPin, unsigned long timeoutUs = 30000UL);

    // Configures the trig/echo pins. Call once from setup().
    void begin();

    // Returns distance in centimeters, or -1 if the reading timed out
    // (no echo received, e.g. nothing in range).
    float readDistanceCM();

  private:
    uint8_t _trigPin;
    uint8_t _echoPin;
    unsigned long _timeoutUs;
};

#endif
