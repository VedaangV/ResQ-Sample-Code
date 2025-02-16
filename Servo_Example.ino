#include <Servo.h>

/*
This example code uses the Arduino servo library to easily control a servo motor.

Wiring: 
Power (Red) - connects to 5V on the board
Ground (Black) - connects to GND on the board
Signal (White or Yellow) - connects to a digital pin on the board

*/

Servo myservo;  // create servo object to control a servo



int pos = 0;    // variable to store the servo position
const int pin = 9; //servo pin

void setup() {
  myservo.attach(pin);  // attaches the servo on the specified pin to the myservo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);              // tell servo to go to position
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}