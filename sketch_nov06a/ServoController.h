#pragma once
#include <Servo.h>

class ServoController
{
  public:
    ServoController();
    void SetServoPosition();
  private:
   Servo servoHwdController;
};
