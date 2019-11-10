#pragma once
#include <Servo.h>
#include "Logger.h"
#include "Types.h"

class ServoController
{
  public:
    ServoController(Logger* logger);
    void Init();
    void SetServoPosition(ServoRawTypes::ServoIndexIds servoId, int newPos);
  private:
   Servo servoHwdController[6];
   bool isInit;
   Logger* logger;
};
