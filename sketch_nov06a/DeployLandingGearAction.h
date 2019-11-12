#pragma once
#include "RetractAction.h"
#include "ServoController.h"

class DeployLandingGearAction : public RetractAction
{
  public:
    DeployLandingGearAction(ServoController* servoController);
    void Execute();
  private:
    ServoController* servoController;
    const int SetPoint = 0;  
};
