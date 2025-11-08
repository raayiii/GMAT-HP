#include <Adafruit_BNO055.h> 
#include <Adafruit_Sensor.h>
#include <Wire.h> 

Adafruit_BNO055 bno = Adafruit_BNO055(55); 

const long INTERVAL_CETAK_MS = 1000;
unsigned long waktuTerakhirCetak = 0;

void loop() {
  unsigned long waktuSekarang = millis();
  if (waktuSekarang - waktuTerakhirCetak >= INTERVAL_CETAK_MS) {
    waktuTerakhirCetak = waktuSekarang; 

    imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
    float yaw   = euler.x();
    float roll  = euler.y();
    float pitch = euler.z();

    Serial.println("--------------------");
    Serial.print("PITCH (Z): "); Serial.print(pitch, 2); Serial.println(" derajat");
    Serial.print("ROLL (Y):  "); Serial.print(roll, 2);  Serial.println(" derajat");
    Serial.print("YAW (X):   "); Serial.print(yaw, 2);   Serial.println(" derajat");
  }
}