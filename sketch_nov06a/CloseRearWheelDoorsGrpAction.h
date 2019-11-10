#pragma once
#include "RetractGroupAction.h"
#include "ServoController.h"

class CloseRearWheelDoorsGrpAction : public RetractGroupAction
{
  public:
    CloseRearWheelDoorsGrpAction(ServoController* servoController);
    void Execute();
  private:
    ServoController* servoController;
    const int SetPoint = 0;
};
