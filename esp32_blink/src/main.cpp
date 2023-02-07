/*
 * ESP32 LED Blink Example
 * Board ESP23 DEVKIT V1
 * 
 * ON Board LED GPIO 2
 */
#include <Arduino.h>
#define BUILT_IN_LED 2

void setup() {
  // Set pin mode
  pinMode(BUILT_IN_LED,OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(BUILT_IN_LED,HIGH);
  delay(500);
  digitalWrite(BUILT_IN_LED,LOW);
}