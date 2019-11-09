#pragma once
#include "RetractGroupAction.h"
#include "ServoController.h"

class OpenRearWheelDoorsGrpAction : public RetractGroupAction
{
  public:
    OpenRearWheelDoorsGrpAction(ServoController* servoController);
    void Execute();
  private:
    ServoController* servoController;
};
