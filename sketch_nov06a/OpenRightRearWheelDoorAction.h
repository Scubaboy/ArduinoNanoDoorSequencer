#pragma once
#include "RetractAction.h"
#include "PWMController.h"

class OpenRightRearWheelDoorAction : public RetractAction
{
  public:
    void Execute();
  private:
    RetractTypes::Action action;
    int duration;
    PWMController* pwmController;
    int pin;
}
