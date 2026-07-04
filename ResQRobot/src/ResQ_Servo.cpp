#include "ResQ_Servo.h"

ResQServo::ResQServo(uint8_t pin, int minAngle, int maxAngle)
  : _pin(pin), _minAngle(minAngle), _maxAngle(maxAngle), _currentAngle(minAngle) {
}

void ResQServo::begin() {
  _servo.attach(_pin);
  setAngle(_currentAngle);
}

void ResQServo::setAngle(int angle) {
  _currentAngle = constrain(angle, _minAngle, _maxAngle);
  _servo.write(_currentAngle);
}

int ResQServo::getAngle() const {
  return _currentAngle;
}
