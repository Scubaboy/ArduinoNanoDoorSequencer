#include "OpenRearWheelDoorsGrpAction.h"
#include "Types.h"
#include "Arduino.h"

OpenRearWheelDoorsGrpAction::OpenRearWheelDoorsGrpAction(ServoController* servoController)
{
  this->servoController= servoController;
}

void OpenRearWheelDoorsGrpAction::Execute()
{
  int tick = 0;
  
  while (tick != this->SetPoint)
  {
    this->servoController->SetServoPosition(ServoRawTypes::ServoIndex6, tick);
    this->servoController->SetServoPosition(ServoRawTypes::ServoIndex5, tick);

    tick +=1;
    delay(20);
  }
}
