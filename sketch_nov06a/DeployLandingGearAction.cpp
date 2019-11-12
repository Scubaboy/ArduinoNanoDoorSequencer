#include "DeployLandingGearAction.h"
#include "Arduino.h"

DeployLandingGearAction::DeployLandingGearAction(ServoController* servoController)
{
  this->servoController= servoController;
}

void DeployLandingGearAction::Execute()
{
  this->servoController->SetServoPosition(ServoRawTypes::ServoIndex1, 180);
  this->servoController->SetServoPosition(ServoRawTypes::ServoIndex3, 180);
  this->servoController->SetServoPosition(ServoRawTypes::ServoIndex4, 180);
  delay(5000);
}
