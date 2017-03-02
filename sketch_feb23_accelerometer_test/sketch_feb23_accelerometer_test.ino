#include "CurieIMU.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Initializing IMU device...");

  CurieIMU.begin();

  CurieIMU.setAccelerometerRange(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  float ax, ay, az;

  CurieIMU.readAccelerometerScaled(ax, ay, az);
  Serial.print("a (x,y,z): \t");
  Serial.print(9.81*ax);
  Serial.print("\t");
  Serial.print(9.81*ay);
  Serial.print("\t");
  Serial.print(9.81*az);
  Serial.println();
  delay(500);
}
