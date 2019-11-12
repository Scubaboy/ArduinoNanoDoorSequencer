#pragma once
#include "RetractGroupAction.h"
#include "ServoController.h"

class RetractLandingGearGrpAction : public RetractGroupAction
{
  public:
    RetractLandingGearGrpAction(ServoController* servoController);
    void Execute();
  private:
    ServoController* servoController;
    const int SetPoint = 0;
};
