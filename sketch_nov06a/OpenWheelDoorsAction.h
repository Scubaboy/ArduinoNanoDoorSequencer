#pragma once
#include "RetractAction.h"
#include "ServoController.h"

class OpenWheelDoorsAction : public RetractAction
{
  public:
    OpenWheelDoorsAction(ServoController* servoController);
    void Execute();
  private:
    ServoController* servoController;
    const int SetPoint = 180;
};
