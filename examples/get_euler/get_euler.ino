#include <Arduino.h>

#include "mpu6050.h"

Mpu6050 mpu6050(0x68);

void setup() {
  Serial.begin(115200);
  mpu6050.Setup();
  Serial.println("setup done");
}

void loop() {
  if (mpu6050.UpdateQuaternion()) {
    const auto euler = mpu6050.GetEuler();
    Serial.print("yaw: ");
    Serial.print(euler.yaw);
    Serial.print(", pitch: ");
    Serial.print(euler.pitch);
    Serial.print(", roll: ");
    Serial.println(euler.roll);
  }
}