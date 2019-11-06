#include "RetractController.h"

RetractController::RetractController (PWMController* pwmController)
{
  this->pwmController = pwmController;
}

void RetractController::ProcessRetractAction(RetractAction* action)
{
  action->Execute();
}

RetractTypes::RetractPosition RetractController::RetractPosition()
{
  if (this->pwmController != 0)
  {
    int pulseDuration = this->pwmController->PWMPulseDuration();

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
