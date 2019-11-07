#pragma once
#include "PWMController.h"
#include "Types.h"
#include "RetractAction.h"
#include "RetractGroupAction.h"

class RetractController
{
  public:
    RetractController (PWMController* pwmController);
    RetractTypes::RetractPosition RetractPosition();
    void ProcessRetractAction(RetractAction* action);
    void ProcessRetractGroupAction(RetractGroupAction* groupAction);
  private:

  PWMController* pwmController;
  
};
