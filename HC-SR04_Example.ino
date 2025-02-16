/*
This example code is for the HC-SR04 ping (distance) sensor. 
The sensor works by sending out a wave through the transmitter, and receiving its echo with the receiver after it bounces off an object.
The time of the wave's travel is recorded and converted from microseconds to centimeters.
*/


//defines pin numbers
//trig pin - controls the transmitter
//echo pin - controls the receiver
const int trigPin = 9;
const int echoPin = 10;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin to output
  pinMode(echoPin, INPUT); // Sets the echoPin to input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds (sending the wave)
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  int distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distance);
}