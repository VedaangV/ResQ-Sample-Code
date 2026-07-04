This repository contains sample code to help you get started with the ResQ robot kit!

Here, you can find files with examples on reading from sensors, moving the robot, and more.

NOTE: The sample codes are still under progress. 

## ResQRobot library

The [`ResQRobot/`](ResQRobot/) folder contains a full Arduino library that
wraps every sensor and actuator on the kit (APDS9960 color sensor, BNO055
IMU, VL53L0X time-of-flight sensor, HC-SR04 ultrasonic sensor, servo, and
the two TT tread motors) into simple, documented classes, plus 7 ready-to-run
examples. It's the recommended starting point if you don't want to
copy-paste and adapt the raw examples above by hand.

### Installing the library

The library already lives in this repo as a normal folder
(`ResQRobot/`), which is exactly the layout Arduino expects. You just need
to get a copy of that folder onto your computer, in the right place, as a
`.zip` (or a plain folder copy).

**Option A - Download a ZIP from GitHub (no git required)**

1. On the repository's GitHub page, click the green **Code** button > **Download ZIP**. This downloads the *whole repo*, not just the library.
2. Unzip it. Inside, find the `ResQRobot` folder (e.g. `ResQ-Sample-Code-main/ResQRobot`).
3. Re-zip just that `ResQRobot` folder so you end up with a `ResQRobot.zip` whose contents are `ResQRobot/library.properties`, `ResQRobot/src/...`, etc. (not nested in an extra folder).
   - macOS/Linux: `cd ResQ-Sample-Code-main && zip -r ResQRobot.zip ResQRobot`
   - Windows: select the `ResQRobot` folder, right-click > **Send to > Compressed (zipped) folder**.
4. In the Arduino IDE: **Sketch > Include Library > Add .ZIP Library...** and select `ResQRobot.zip`.

**Option B - Clone with git**

```bash
git clone https://github.com/vedaangv/resq-sample-code.git
cd resq-sample-code
zip -r ResQRobot.zip ResQRobot
```

Then use **Add .ZIP Library...** as in step 4 above, pointing at the `ResQRobot.zip` you just created.

**Option C - Manual copy (no zipping needed)**

Copy the `ResQRobot` folder directly into your Arduino libraries directory:

- Windows: `Documents\Arduino\libraries\ResQRobot`
- macOS: `~/Documents/Arduino/libraries/ResQRobot`
- Linux: `~/Arduino/libraries/ResQRobot`

Restart the Arduino IDE afterward so it picks up the new library.

### After installing

1. Install the sensor dependencies via **Sketch > Include Library > Manage Libraries...**: search for and install *Adafruit APDS9960 Library*, *Adafruit BNO055*, *Adafruit Unified Sensor*, and *Adafruit VL53L0X*.
2. Open an example from **File > Examples > ResQRobot** to confirm it shows up and compiles.
3. See [`ResQRobot/README.md`](ResQRobot/README.md) for the full API reference and usage examples.

