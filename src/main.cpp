#include <Arduino.h>
#include "libRobusMotors.h"
#include "LibRobus.h"

void setup() {
  BoardInit();
  Serial.begin(115200);
}

void loop() {
    delay(3000);
    MOTOR_SetSpeed(0,0.35);
    MOTOR_SetSpeed(1,0.35);
    ENCODER_ReadReset(0);
    ENCODER_ReadReset(1);
    MOTOR_SetSpeed(0,0.75);
    MOTOR_SetSpeed(1,0.75);
    delay(1000);
    MOTOR_SetSpeed(0,0);
    MOTOR_SetSpeed(1,0);
    while(1);

}