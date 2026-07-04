/*
  ResQRobot.h
  Convenience facade for the ResQ Rescue Line kit. Wires together the
  color sensor, IMU, ultrasonic sensor, time-of-flight sensor, servo, and
  drive motors using the kit's default pin layout, so you can get a robot
  up and running with just:

    ResQRobot robot;

    void setup() {
      Serial.begin(115200);
      robot.begin();
    }

  Each subsystem is also exposed as its own class (ResQMotors,
  ResQColorSensor, ResQImu, ResQUltrasonic, ResQTofSensor, ResQServo) if
  you'd rather wire pins yourself or only need a subset of the kit -
  see the individual headers in this folder, and the examples/ folder.
*/
#ifndef ResQRobot_h
#define ResQRobot_h

#include <Arduino.h>
#include "ResQ_Motors.h"
#include "ResQ_ColorSensor.h"
#include "ResQ_IMU.h"
#include "ResQ_Ultrasonic.h"
#include "ResQ_ToF.h"
#include "ResQ_Servo.h"

// Default pin layout for the ResQ kit's wiring. If your build uses
// different pins, skip ResQRobot and construct the individual classes
// (ResQMotors, ResQUltrasonic, ResQServo, ...) with your own pin numbers.
#define RESQ_DEFAULT_TRIG_PIN   9
#define RESQ_DEFAULT_ECHO_PIN   10
#define RESQ_DEFAULT_SERVO_PIN  11
#define RESQ_DEFAULT_L_IN1      4
#define RESQ_DEFAULT_L_IN2      5
#define RESQ_DEFAULT_L_PWM      3
#define RESQ_DEFAULT_R_IN1      7
#define RESQ_DEFAULT_R_IN2      8
#define RESQ_DEFAULT_R_PWM      6

class ResQRobot {
  public:
    ResQRobot();

    // Initializes I2C and every subsystem. Never halts the program: if a
    // sensor fails to initialize, its failure is reported (via Serial, if
    // verbose is true) and reflected in the returned bool so your code can
    // decide how to react (e.g. run without that sensor, blink an LED, etc).
    // Returns true only if every subsystem initialized successfully.
    bool begin(bool verbose = true);

    // Public subsystems - use these directly for full control.
    ResQMotors motors;
    ResQColorSensor colorSensor;
    ResQImu imu;
    ResQUltrasonic ultrasonic;
    ResQTofSensor tof;
    ResQServo gripperServo;

  private:
    bool _verbose;
    bool initSubsystem(bool ok, const char *name);
};

#endif
