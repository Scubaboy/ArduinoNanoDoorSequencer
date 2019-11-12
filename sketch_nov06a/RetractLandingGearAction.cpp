#include "RetractLandingGearAction.h"
#include "Arduino.h"

RetractLandingGearAction::RetractLandingGearAction(ServoController* servoController)
{
  this->servoController= servoController;
}

void RetractLandingGearAction::Execute()
{
    this->servoController->SetServoPosition(ServoRawTypes::ServoIndex1, 0);
    this->servoController->SetServoPosition(ServoRawTypes::ServoIndex3, 0);
    this->servoController->SetServoPosition(ServoRawTypes::ServoIndex4, 0);
    delay(5000);

}
