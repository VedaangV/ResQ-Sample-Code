#include "ResQ_Ultrasonic.h"

ResQUltrasonic::ResQUltrasonic(uint8_t trigPin, uint8_t echoPin, unsigned long timeoutUs)
  : _trigPin(trigPin), _echoPin(echoPin), _timeoutUs(timeoutUs) {
}

void ResQUltrasonic::begin() {
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
  digitalWrite(_trigPin, LOW);
}

float ResQUltrasonic::readDistanceCM() {
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);

  unsigned long duration = pulseIn(_echoPin, HIGH, _timeoutUs);
  if (duration == 0) {
    return -1;
  }
  return duration * 0.034f / 2.0f;
}
