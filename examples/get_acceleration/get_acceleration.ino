#include <Arduino.h>

#include "mpu6050.h"

Mpu6050 mpu6050(0x68);

void setup() {
  Serial.begin(115200);
  mpu6050.Setup();
  Serial.println("setup done");
}

void loop() {
  if (mpu6050.UpdateMotionInfo()) {
    const auto acceleration = mpu6050.GetAcceleration();
    Serial.print("acceleration x: ");
    Serial.print(acceleration.x);
    Serial.print(", y: ");
    Serial.print(acceleration.y);
    Serial.print(", z: ");
    Serial.println(acceleration.z);
  }
}