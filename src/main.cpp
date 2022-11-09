// Avengeance's child program for Arduino Micro

#include <Arduino.h>
#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Serial.println(
      "This is Arduino Micro, Sending message to PC on Serial Connection.");
}

void loop() {}