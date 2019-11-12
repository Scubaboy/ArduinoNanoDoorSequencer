#pragma once
#include "RetractAction.h"
#include "ServoController.h"

class RetractLandingGearAction : public RetractAction
{
  public:
    RetractLandingGearAction(ServoController* servoController);
    void Execute();
  private:
    ServoController* servoController;
    const int SetPoint = 0;
};
