#pragma once
#include "RetractAction.h"
#include "ServoController.h"

class CloseWheelDoorsAction : public RetractAction
{
  public:
    CloseWheelDoorsAction(ServoController* servoController);
    void Execute();
  private:
    ServoController* servoController;
    const int SetPoint = 0;
};
