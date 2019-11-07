#pragma once
#include "PWMInputController.h"
#include "Types.h"
#include "RetractAction.h"
#include "RetractGroupAction.h"

class RetractController
{
  public:
    RetractController (PWMInputController* pwmInputController);
    RetractTypes::RetractPosition RetractPosition();
    void ProcessRetractAction(RetractAction* action);
    void ProcessRetractGroupAction(RetractGroupAction* groupAction);
  private:

  PWMInputController* pwmInputController;
  
};
