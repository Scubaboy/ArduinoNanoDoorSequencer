#include "RetractController.h"
#include "Arduino.h"

RetractController::RetractController (PWMInputController* pwmInputController, Logger* logger)
{
  this->pwmInputController = pwmInputController;
  this->logger = logger;
  this->lastPosition = RetractTypes::UnDefined;
}

void RetractController::ProcessRetractAction(RetractAction* action)
{
  action->Execute();
}

void RetractController::ProcessRetractGroupAction(RetractGroupAction* action)
{
  action->Execute();
}

RetractTypes::RetractPosition RetractController::RetractPosition()
{
  if (this->pwmInputController != 0)
  {    
    int pulseDuration = this->pwmInputController->PWMPulseDuration();
    
    if (pulseDuration >= ServoRawTypes::ServoUp)
    {
        if (this->lastPosition != RetractTypes::Up)
        {
          this->logger->Log("RetractController::RetractPostion -> rcPWMInput Up Requested");
          this->lastPosition = RetractTypes::Up;
        }
        
        return RetractTypes::Up;
    }
    else if (pulseDuration <= ServoRawTypes::ServoDown)
    {
        if (this->lastPosition != RetractTypes::Down)
        {
          this->logger->Log("RetractController::RetractPostion -> rcPWMInput Down Requested");
          this->lastPosition = RetractTypes::Down;
        }
        
        return RetractTypes::Down;
    }
    else
    {
      if (this->lastPosition != RetractTypes::UnDefined)
      {
        this->logger->Log("RetractController::RetractPostion -> rcPWMInput Middle Detected!");
        this->lastPosition = RetractTypes::UnDefined;
      }
      return RetractTypes::UnDefined;
    }
  }

  return RetractTypes::UnDefined;
}
