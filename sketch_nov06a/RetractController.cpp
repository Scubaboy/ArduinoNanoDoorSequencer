#include "RetractController.h"
#include "Arduino.h"

RetractController::RetractController (PWMInputController* pwmInputController, Logger* logger)
{
  this->pwmInputController = pwmInputController;
  this->logger = logger;
}

void RetractController::ProcessRetractAction(RetractAction* action)
{
  action->Execute();
}

RetractTypes::RetractPosition RetractController::RetractPosition()
{
  char pulseDurationNotification[90] = {'\0'};
  
  if (this->pwmInputController != 0)
  {
    int pulseDuration = this->pwmInputController->PWMPulseDuration();

    sprintf(pulseDurationNotification,"Retract::RetractPosition -> rcPWMInput Pulse Duration %d",pulseDuration);
    this->logger->Log(pulseDurationNotification);
    
    if (pulseDuration >= ServoRawTypes::ServoUp)
    {
        this->logger->Log("RetractController::RetractPostion -> rcPWMInput Up Requested");
        return RetractTypes::Up;
    }
    else if (pulseDuration <= ServoRawTypes::ServoDown && pulseDuration > 0)
    {
        this->logger->Log("RetractController::RetractPostion -> rcPWMInput Down Requested");
        return RetractTypes::Down;
    }

    this->logger->Log("RetractController::RetractPostion -> rcPWMInput Not Detected!");
    return RetractTypes::UnDefined;
  }

  return RetractTypes::UnDefined;
}
