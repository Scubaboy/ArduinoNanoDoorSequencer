#include "RetractController.h"

RetractController::RetractController (PWMInputController* pwmInputController)
{
  this->pwmInputController = pwmInputController;
}

void RetractController::ProcessRetractAction(RetractAction* action)
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
        return RetractTypes::Up;
    }
    else if (pulseDuration <= ServoRawTypes::ServoDown)
    {
      return RetractTypes::Down;
    }

    return RetractTypes::UnDefined;
  }

  return RetractTypes::UnDefined;
}
