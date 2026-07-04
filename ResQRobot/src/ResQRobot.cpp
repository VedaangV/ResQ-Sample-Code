#include "ResQRobot.h"
#include <Wire.h>

ResQRobot::ResQRobot()
  : motors(RESQ_DEFAULT_L_IN1, RESQ_DEFAULT_L_IN2, RESQ_DEFAULT_L_PWM,
           RESQ_DEFAULT_R_IN1, RESQ_DEFAULT_R_IN2, RESQ_DEFAULT_R_PWM),
    ultrasonic(RESQ_DEFAULT_TRIG_PIN, RESQ_DEFAULT_ECHO_PIN),
    gripperServo(RESQ_DEFAULT_SERVO_PIN),
    _verbose(true) {
}

bool ResQRobot::initSubsystem(bool ok, const char *name) {
  if (_verbose) {
    Serial.print(name);
    Serial.println(ok ? F(": OK") : F(": NOT FOUND"));
  }
  return ok;
}

bool ResQRobot::begin(bool verbose) {
  _verbose = verbose;
  Wire.begin();

  bool allOk = true;
  allOk &= initSubsystem(colorSensor.begin(), "Color sensor (APDS9960)");
  allOk &= initSubsystem(imu.begin(), "IMU (BNO055)");
  allOk &= initSubsystem(tof.begin(), "Time-of-flight sensor (VL53L0X)");

  ultrasonic.begin();
  gripperServo.begin();
  motors.begin();

  if (_verbose) {
    Serial.println(allOk ? F("ResQRobot ready.") : F("ResQRobot ready (with sensor warnings above)."));
  }

  return allOk;
}
