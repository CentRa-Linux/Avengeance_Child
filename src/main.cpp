// Avengeance's child program for Arduino Micro

#include <Arduino.h>
#include <SoftPWM.h>
#include <Wire.h>

int leds[3];

void receiveEvent(int i) {
  int l;
  while (Wire.available()) // loop through all but the last
  {
    int c = Wire.read(); // receive byte as a character
    leds[l] = c;
    l++;
  }
}

void requestEvent() { Serial.println("requested!"); }

void ledsetup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN_RX, OUTPUT);
  pinMode(LED_BUILTIN_TX, OUTPUT);
  SoftPWMBegin();
}

void setup() {
  Serial.begin(9600);
  Serial.println(
      "This is Arduino Micro, Sending message to PC on Serial Connection.");

  Serial.println("Setting up i2c...");
  Wire.begin(0x08);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  Serial.println("i2c Ok!");

  ledsetup();
}

float fade = 0;
float fade2 = 0;

void loop() {
  if (leds[0] == 0) {
    SoftPWMSet(LED_BUILTIN, fade);
  }
  if (leds[0] == 1) {
    SoftPWMSet(LED_BUILTIN, fade2);
  }
  if (leds[0] == 2) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if (leds[0] == 3) {
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (leds[1] == 0) {
    SoftPWMSet(LED_BUILTIN_RX, fade);
  }
  if (leds[1] == 1) {
    SoftPWMSet(LED_BUILTIN_RX, fade2);
  }
  if (leds[1] == 2) {
    digitalWrite(LED_BUILTIN_RX, HIGH);
  }
  if (leds[1] == 3) {
    digitalWrite(LED_BUILTIN_RX, LOW);
  }
  if (leds[2] == 0) {
    SoftPWMSet(LED_BUILTIN_TX, fade);
  }
  if (leds[2] == 1) {
    SoftPWMSet(LED_BUILTIN_TX, fade2);
  }
  if (leds[2] == 2) {
    digitalWrite(LED_BUILTIN_TX, HIGH);
  }
  if (leds[2] == 3) {
    digitalWrite(LED_BUILTIN_TX, LOW);
  }
  if (fade >= 255) {
    fade = 0;
  }
  if (fade2 >= 255) {
    fade2 = 0;
  }
  fade += 0.07;
  fade2 += 0.02;
}
