#include "OpenWheelDoorsAction.h"
#include "Types.h"
#include "Arduino.h"

OpenWheelDoorsAction::OpenWheelDoorsAction(ServoController* servoController)
{
  this->servoController= servoController;
}

void OpenWheelDoorsAction::Execute()
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
