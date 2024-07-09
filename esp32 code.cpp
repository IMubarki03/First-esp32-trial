#include <Arduino.h>

const int motionSensorPin = 14; // pin for the PIR sensor
const int ledPin = 17;          // pin for the LED light

void setup() {
  // Put serial communication
  Serial.begin(115200);

  // Put the motion sensor pin as an input
  pinMode(motionSensorPin, INPUT);

  // Put the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Make sure the LED is always off
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Read any signal from the motion sensor
  int motionState = digitalRead(motionSensorPin);

  // If any motion detected, turn on the LED light
  if (motionState == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(ledPin, HIGH);
  } 
  // If there's no motion, turn off the LED light
  else {
    Serial.println("No motion detected.");
    digitalWrite(ledPin, LOW);
  }

  // Read every 0.5s
  delay(500);
}
