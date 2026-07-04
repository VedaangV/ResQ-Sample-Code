/*
  ResQ_Motors.h
  Driver for the two TT gear motors that power the ResQ kit's treads,
  through a dual H-bridge driver (IN1/IN2 direction pins + PWM speed pin
  per side - e.g. TB6612FNG, L298N, DRV8833, etc.).

  Wiring (defaults used by ResQRobot, override freely):
    Left  motor -> L_IN1, L_IN2, L_PWM
    Right motor -> R_IN1, R_IN2, R_PWM
*/
#ifndef ResQ_Motors_h
#define ResQ_Motors_h

#include <Arduino.h>

class ResQMotors {
  public:
    // Pass the 6 driver pins for the left and right side of the robot.
    ResQMotors(uint8_t leftIn1, uint8_t leftIn2, uint8_t leftPwm,
                uint8_t rightIn1, uint8_t rightIn2, uint8_t rightPwm);

    // Configures all motor pins as OUTPUT. Call once from setup().
    void begin();

    // Drives each side independently. Range is -255..255, negative = reverse.
    void setSpeeds(int leftSpeed, int rightSpeed);

    // Convenience movement helpers. speed is 0..255.
    void forward(int speed = 200);
    void backward(int speed = 200);
    void turnLeft(int speed = 200);   // arcs left (right tread only)
    void turnRight(int speed = 200);  // arcs right (left tread only)
    void pivotLeft(int speed = 200);  // spins in place, left tread reverse
    void pivotRight(int speed = 200); // spins in place, right tread reverse
    void stop();

  private:
    void driveMotor(uint8_t in1, uint8_t in2, uint8_t pwmPin, int speed);

    uint8_t _leftIn1, _leftIn2, _leftPwm;
    uint8_t _rightIn1, _rightIn2, _rightPwm;
};

#endif
