#include "ResQ_Motors.h"

ResQMotors::ResQMotors(uint8_t leftIn1, uint8_t leftIn2, uint8_t leftPwm,
                          uint8_t rightIn1, uint8_t rightIn2, uint8_t rightPwm)
  : _leftIn1(leftIn1), _leftIn2(leftIn2), _leftPwm(leftPwm),
    _rightIn1(rightIn1), _rightIn2(rightIn2), _rightPwm(rightPwm) {
}

void ResQMotors::begin() {
  pinMode(_leftIn1, OUTPUT);
  pinMode(_leftIn2, OUTPUT);
  pinMode(_leftPwm, OUTPUT);
  pinMode(_rightIn1, OUTPUT);
  pinMode(_rightIn2, OUTPUT);
  pinMode(_rightPwm, OUTPUT);
  stop();
}

void ResQMotors::driveMotor(uint8_t in1, uint8_t in2, uint8_t pwmPin, int speed) {
  speed = constrain(speed, -255, 255);

  if (speed > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (speed < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }

  analogWrite(pwmPin, abs(speed));
}

void ResQMotors::setSpeeds(int leftSpeed, int rightSpeed) {
  driveMotor(_leftIn1, _leftIn2, _leftPwm, leftSpeed);
  driveMotor(_rightIn1, _rightIn2, _rightPwm, rightSpeed);
}

void ResQMotors::forward(int speed) {
  setSpeeds(speed, speed);
}

void ResQMotors::backward(int speed) {
  setSpeeds(-speed, -speed);
}

void ResQMotors::turnLeft(int speed) {
  setSpeeds(0, speed);
}

void ResQMotors::turnRight(int speed) {
  setSpeeds(speed, 0);
}

void ResQMotors::pivotLeft(int speed) {
  setSpeeds(-speed, speed);
}

void ResQMotors::pivotRight(int speed) {
  setSpeeds(speed, -speed);
}

void ResQMotors::stop() {
  setSpeeds(0, 0);
}
