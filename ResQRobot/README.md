# ResQRobot

An Arduino library for the ResQ Rescue Line robot kit. It wraps the kit's
sensors and actuators - APDS9960 color sensor, BNO-055 IMU, VL53L0X
time-of-flight sensor, HC-SR04 ultrasonic sensor, a Towerpro MG90D servo, and the two TT
tread-drive motors - into small, well-documented classes so you can write
robot code without re-deriving register-level sensor logic every time.

## What's in the box

Each piece of hardware gets its own class. Use only the ones you need, or
use the `ResQRobot` facade to bring up everything at once with the kit's
default pin layout.

| Class             | Hardware                  | Header                |
|-------------------|----------------------------|------------------------|
| `ResQRobot`       | Everything (facade)        | `ResQRobot.h`          |
| `ResQMotors`      | 2x TT motor + tread drive  | `ResQ_Motors.h`        |
| `ResQColorSensor` | APDS9960 color sensor      | `ResQ_ColorSensor.h`   |
| `ResQImu`         | BNO055 orientation sensor  | `ResQ_IMU.h`           |
| `ResQUltrasonic`  | HC-SR04 ultrasonic sensor  | `ResQ_Ultrasonic.h`    |
| `ResQTofSensor`   | VL53L0X time-of-flight     | `ResQ_ToF.h`           |
| `ResQServo`       | Attachment servo           | `ResQ_Servo.h`         |

## Installation

See the top-level repo README for full install instructions (Library
Manager .ZIP install or manual copy into your `libraries` folder). This
folder itself *is* the library - everything under `ResQRobot/` is what
gets zipped or copied.

### Dependencies

Install these through **Sketch > Include Library > Manage Libraries...**
before using ResQRobot:

- Adafruit APDS9960 Library
- Adafruit BNO055
- Adafruit Unified Sensor
- Adafruit VL53L0X

The `Servo` library used by `ResQServo` ships with the Arduino IDE, so no
extra install is needed for it.

## Quick start

```cpp
#include <ResQRobot.h>

ResQRobot robot;

void setup() {
  Serial.begin(115200);
  robot.begin(); // brings up every sensor + the motors, reports any
                 // that failed to init, but never halts your program
}

void loop() {
  float heading = robot.imu.getHeading();
  float wallCm  = robot.ultrasonic.readDistanceCM();

  robot.motors.forward(150);
  delay(100);
}
```

`ResQRobot` assumes the kit's default wiring:

| Signal          | Pin |
|-----------------|-----|
| HC-SR04 TRIG    | 9   |
| HC-SR04 ECHO    | 10  |
| Servo           | 11  |
| Left motor IN1  | 4   |
| Left motor IN2  | 5   |
| Left motor PWM  | 3   |
| Right motor IN1 | 7   |
| Right motor IN2 | 8   |
| Right motor PWM | 6   |

The color sensor, IMU, and ToF sensor are all I2C, so they just need
SDA/SCL - no extra pin config.

If your wiring differs, skip `ResQRobot` and construct the pieces you need
directly (see [Using individual modules](#using-individual-modules)).

## Using individual modules

```cpp
#include <ResQRobot.h>

ResQMotors motors(4, 5, 3, 7, 8, 6);      // leftIn1, leftIn2, leftPwm, rightIn1, rightIn2, rightPwm
ResQUltrasonic ultrasonic(9, 10);          // trigPin, echoPin
ResQServo gripper(11, 0, 180);             // pin, minAngle, maxAngle
ResQColorSensor colorSensor;
ResQImu imu;
ResQTofSensor tof;

void setup() {
  Serial.begin(115200);
  Wire.begin(); // needed for colorSensor / imu / tof

  motors.begin();
  ultrasonic.begin();
  gripper.begin();
  colorSensor.begin();
  imu.begin();
  tof.begin();
}
```

## API reference

### `ResQMotors`

```cpp
ResQMotors(uint8_t leftIn1, uint8_t leftIn2, uint8_t leftPwm,
           uint8_t rightIn1, uint8_t rightIn2, uint8_t rightPwm);

void begin();
void setSpeeds(int leftSpeed, int rightSpeed); // -255..255 each, negative = reverse
void forward(int speed = 200);
void backward(int speed = 200);
void turnLeft(int speed = 200);   // arcs left, right tread only
void turnRight(int speed = 200);  // arcs right, left tread only
void pivotLeft(int speed = 200);  // spins in place
void pivotRight(int speed = 200); // spins in place
void stop();
```

### `ResQColorSensor`

```cpp
bool begin();
bool colorReady();
void readColor(uint16_t &r, uint16_t &g, uint16_t &b, uint16_t &c);
```

### `ResQImu`

```cpp
ResQImu(int32_t sensorId = 55, uint8_t address = 0x28, TwoWire *wire = &Wire);

bool begin();
void getOrientation(float &x, float &y, float &z); // x=heading/yaw, y=roll, z=pitch
float getHeading();  // shortcut for orientation.x, handy for turns
void getCalibration(uint8_t &system, uint8_t &gyro, uint8_t &accel, uint8_t &mag); // 0-3 each
bool isFullyCalibrated();
```

### `ResQUltrasonic`

```cpp
ResQUltrasonic(uint8_t trigPin, uint8_t echoPin, unsigned long timeoutUs = 30000UL);

void begin();
float readDistanceCM(); // returns -1 if the reading timed out (no echo)
```

### `ResQTofSensor`

```cpp
bool begin();
int readDistanceMM(); // returns -1 if out of range
```

### `ResQServo`

```cpp
ResQServo(uint8_t pin, int minAngle = 0, int maxAngle = 180);

void begin();
void setAngle(int angle); // clamped to [minAngle, maxAngle]
int getAngle() const;
```

### `ResQRobot` (facade)

```cpp
bool begin(bool verbose = true); // returns true only if every sensor initialized OK

ResQMotors motors;
ResQColorSensor colorSensor;
ResQImu imu;
ResQUltrasonic ultrasonic;
ResQTofSensor tof;
ResQServo gripperServo;
```

## Examples

Open via **File > Examples > ResQRobot** in the Arduino IDE:

1. `01_ColorSensor` - print raw color channel values
2. `02_IMU_Orientation` - print heading/roll/pitch + calibration status
3. `03_Ultrasonic` - print HC-SR04 distance in cm
4. `04_TimeOfFlight` - print VL53L0X distance in mm
5. `05_GripperServo` - sweep a servo attachment
6. `06_Motors` - basic drive pattern (forward/pivot/backward)
7. `07_FullRobot` - bring up every subsystem via `ResQRobot` and print all readings
