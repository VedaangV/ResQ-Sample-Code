/*

This example code is used to get r, g, b, and c values from the APDS9960 color sensor.
r, g, b - red/green/blue light intesnity
c - clear channel, overall light intensity

Make sure the Adafruit_APDS9960 library is installed before you run this code (you can install it from the library manager)

*/

#include <Wire.h>
#include <Adafruit_APDS9960.h>

Adafruit_APDS9960 apds;  // Create APDS9960 object

void setup() {
    // Initialize serial
    Serial.begin(9600);
    
    // Initialize the sensor
    if (!apds.begin()) {
        Serial.println("APDS-9960 initialization failed!");
        while (1);
    }

    Serial.println("APDS-9960 initialized.");

    // Enable color sensing
    apds.enableColor(true);
}

void loop() {
    uint16_t r, g, b, c;  // Variables for storing RGB and clear values

    // Check if color data is available
    if (apds.colorDataReady()) {
        apds.getColorData(&r, &g, &b, &c); // Read color values

        // Print values to Serial Monitor
        Serial.print("R: "); Serial.print(r);
        Serial.print(" G: "); Serial.print(g);
        Serial.print(" B: "); Serial.print(b);
        Serial.print(" C: "); Serial.println(c);
    }

    delay(500);  // Delay before next reading
}
