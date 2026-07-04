/*
  02_IMU_Orientation
  Reads absolute orientation from the BNO055 and prints the heading (X
  axis) that teams typically use to make accurate turns, plus calibration
  status so you know when the readings can be trusted.
*/
#include <ResQRobot.h>

ResQImu imu;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  if (!imu.begin()) {
    Serial.println("BNO055 not found - check wiring!");
    while (1);
  }
}

void loop() {
  float x, y, z;
  imu.getOrientation(x, y, z);

  uint8_t sys, gyro, accel, mag;
  imu.getCalibration(sys, gyro, accel, mag);

  Serial.print("Heading (X): "); Serial.print(x, 2);
  Serial.print("  Roll (Y): "); Serial.print(y, 2);
  Serial.print("  Pitch (Z): "); Serial.print(z, 2);
  Serial.print("  | Calibration sys:"); Serial.print(sys);
  Serial.print(" gyro:"); Serial.print(gyro);
  Serial.print(" accel:"); Serial.print(accel);
  Serial.print(" mag:"); Serial.println(mag);

  delay(100);
}
