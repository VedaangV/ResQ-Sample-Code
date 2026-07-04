/*
  06_Motors
  Drives the two tread motors through a basic movement pattern: forward,
  stop, pivot left, pivot right, backward, stop. Adjust SPEED and the pin
  numbers below to match your driver wiring.
*/
#include <ResQRobot.h>

const int L_IN1 = 4;
const int L_IN2 = 5;
const int L_PWM = 3;
const int R_IN1 = 7;
const int R_IN2 = 8;
const int R_PWM = 6;

const int SPEED = 180; // 0-255

ResQMotors motors(L_IN1, L_IN2, L_PWM, R_IN1, R_IN2, R_PWM);

void setup() {
  motors.begin();
}

void loop() {
  motors.forward(SPEED);
  delay(1000);

  motors.stop();
  delay(300);

  motors.pivotLeft(SPEED);
  delay(500);

  motors.pivotRight(SPEED);
  delay(500);

  motors.backward(SPEED);
  delay(1000);

  motors.stop();
  delay(1000);
}
