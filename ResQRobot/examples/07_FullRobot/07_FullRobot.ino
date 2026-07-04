/*
  07_FullRobot
  Brings up every subsystem on the ResQ kit through the ResQRobot facade
  and prints all sensor readings, mirroring what a real run loop looks
  like. Start here, then split pieces out into your own robot logic.

  Uses the kit's default pin layout (see ResQRobot.h). If your wiring is
  different, construct ResQMotors/ResQUltrasonic/ResQServo directly with
  your own pins instead of using ResQRobot.
*/
#include <ResQRobot.h>

ResQRobot robot;

void setup() {
  Serial.begin(115200);
  robot.begin(); // prints OK/NOT FOUND per sensor, never halts
}

void loop() {
  uint16_t r, g, b, c;
  if (robot.colorSensor.colorReady()) {
    robot.colorSensor.readColor(r, g, b, c);
  }

  float heading = robot.imu.getHeading();
  float ultrasonicCm = robot.ultrasonic.readDistanceCM();
  int tofMm = robot.tof.readDistanceMM();

  Serial.println("---- SENSOR READINGS ----");
  Serial.print("Color R:"); Serial.print(r);
  Serial.print(" G:"); Serial.print(g);
  Serial.print(" B:"); Serial.print(b);
  Serial.print(" C:"); Serial.println(c);

  Serial.print("Heading: "); Serial.println(heading);
  Serial.print("Ultrasonic (cm): "); Serial.println(ultrasonicCm);
  Serial.print("ToF (mm): "); Serial.println(tofMm);

  // Keep the gripper servo centered and drive forward slowly as a demo.
  robot.gripperServo.setAngle(90);
  robot.motors.forward(120);

  delay(200);
}
