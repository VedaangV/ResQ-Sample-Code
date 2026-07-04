/*
  ResQ_Servo.h
  Thin wrapper around the standard Servo library, constrained to a safe
  angle range. Teams typically use this servo to power an attachment such
  as a rescue-kit dropper/gripper for the evacuation zone.
*/
#ifndef ResQ_Servo_h
#define ResQ_Servo_h

#include <Arduino.h>
#include <Servo.h>

class ResQServo {
  public:
    // minAngle/maxAngle let you clamp travel for a mechanism that
    // shouldn't swing the full 0-180 degrees.
    ResQServo(uint8_t pin, int minAngle = 0, int maxAngle = 180);

    // Attaches the servo to its pin. Call once from setup().
    void begin();

    // Moves to the given angle, clamped to [minAngle, maxAngle].
    void setAngle(int angle);

    // Last angle written to the servo.
    int getAngle() const;

  private:
    Servo _servo;
    uint8_t _pin;
    int _minAngle;
    int _maxAngle;
    int _currentAngle;
};

#endif
