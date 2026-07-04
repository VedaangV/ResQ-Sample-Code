/*
  05_GripperServo
  Sweeps a servo back and forth between its configured limits. Teams
  typically use a servo like this to power an attachment, such as a
  rescue-kit dropper for the evacuation zone.
*/
#include <ResQRobot.h>

const int SERVO_PIN = 11;

// Clamp travel to 0-180 degrees; narrow this range if your mechanism
// shouldn't swing that far.
ResQServo gripperServo(SERVO_PIN, 0, 180);

void setup() {
  gripperServo.begin();
}

void loop() {
  for (int angle = 0; angle <= 180; angle += 5) {
    gripperServo.setAngle(angle);
    delay(20);
  }
  for (int angle = 180; angle >= 0; angle -= 5) {
    gripperServo.setAngle(angle);
    delay(20);
  }
}
