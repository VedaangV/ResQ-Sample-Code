/*
  03_Ultrasonic
  Reads distance in centimeters from the HC-SR04 ultrasonic sensor.
  Teams typically use this to detect walls/obstacles ahead of the robot.
*/
#include <ResQRobot.h>

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

ResQUltrasonic ultrasonic(TRIG_PIN, ECHO_PIN);

void setup() {
  Serial.begin(115200);
  ultrasonic.begin();
}

void loop() {
  float distanceCm = ultrasonic.readDistanceCM();

  if (distanceCm < 0) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance (cm): ");
    Serial.println(distanceCm);
  }

  delay(100);
}
