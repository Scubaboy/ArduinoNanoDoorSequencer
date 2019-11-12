#pragma once
#include "RetractGroupAction.h"
#include "ServoController.h"

class DeployLandingGearGrpAction : public RetractGroupAction
{
  public:
    DeployLandingGearGrpAction(ServoController* servoController);
    void Execute();
  private:
    ServoController* servoController;
    const int SetPoint = 0;  
};
