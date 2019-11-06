#pragma once
#include "PWMController.h"
#include "Types.h"
#include "RetractAction.h"

class RetractController
{
  public:
    RetractController (PWMController* pwmController);
    RetractTypes::RetractPosition RetractPosition();
    void ProcessRetractAction(RetractAction* action);
  private:

  PWMController* pwmController;
  
};
