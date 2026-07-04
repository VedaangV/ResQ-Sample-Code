/*
  01_ColorSensor
  Reads raw red/green/blue/clear values from the APDS9960 color sensor.
  Useful for detecting floor tile colors along the rescue line course.
*/
#include <ResQRobot.h>

ResQColorSensor colorSensor;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  if (!colorSensor.begin()) {
    Serial.println("Color sensor not found - check wiring!");
    while (1);
  }
}

void loop() {
  if (colorSensor.colorReady()) {
    uint16_t r, g, b, c;
    colorSensor.readColor(r, g, b, c);

    Serial.print("R: "); Serial.print(r);
    Serial.print(" G: "); Serial.print(g);
    Serial.print(" B: "); Serial.print(b);
    Serial.print(" C: "); Serial.println(c);
  }

  delay(200);
}
