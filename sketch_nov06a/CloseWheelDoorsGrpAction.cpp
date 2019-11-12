#include "CloseWheelDoorsGrpAction.h"
#include "Types.h"
#include "Arduino.h"

CloseWheelDoorsGrpAction::CloseWheelDoorsGrpAction(ServoController* servoController)
{
  this->servoController= servoController;
}

void CloseWheelDoorsGrpAction::Execute()
{
  int step = 180;
  
  while (step != this->SetPoint)
  {
    this->servoController->SetServoPosition(ServoRawTypes::ServoIndex6, step);
    this->servoController->SetServoPosition(ServoRawTypes::ServoIndex5, step);

    step -=1;
    delay(20);
  }
}
