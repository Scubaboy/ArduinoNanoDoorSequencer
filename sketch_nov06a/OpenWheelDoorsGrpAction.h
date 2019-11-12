#pragma once
#include "RetractGroupAction.h"
#include "ServoController.h"

class OpenWheelDoorsGrpAction : public RetractGroupAction
{
  public:
    OpenWheelDoorsGrpAction(ServoController* servoController);
    void Execute();
  private:
    ServoController* servoController;
    const int SetPoint = 180;
};
