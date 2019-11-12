#pragma once
#include "RetractGroupAction.h"
#include "ServoController.h"

class CloseWheelDoorsGrpAction : public RetractGroupAction
{
  public:
    CloseWheelDoorsGrpAction(ServoController* servoController);
    void Execute();
  private:
    ServoController* servoController;
    const int SetPoint = 0;
};
