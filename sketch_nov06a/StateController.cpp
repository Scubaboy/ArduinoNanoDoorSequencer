#include "StateController.h"
#include <EEPROM.h>

void StateController::Init()
{
  EEPROM.get( this->baseAddress, this->currentState );
  this->isInit = true;
}

RetractTypes::RetractPosition StateController::RequestLastRetractPosition()
{
  if (this->isInit)
  {
    return this->currentState.LastRetractPosition;
  }

  return RetractTypes::UnDefined;
}

void StateController::UpdateLastRetractPosition(RetractTypes::RetractPosition retractPosition)
{
  if (this->isInit)
  {
    this->currentState.LastRetractPosition = retractPosition;
    EEPROM.put(this->baseAddress, this->currentState);
  }
}

bool StateController::IsSynched(RetractTypes::RetractPosition retractPosition)
{
  return retractPosition == this->currentState.LastRetractPosition;
}

SystemState::ServoAttributes* StateController::GetServoAttributes()
{
  return this->currentState.servoAttributes;
}
