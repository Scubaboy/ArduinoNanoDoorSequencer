#pragma once
#include "PWMInputController.h"
#include "Types.h"
#include "RetractAction.h"
#include "RetractGroupAction.h"
#include "Logger.h"

class RetractController
{
  public:
    RetractController (PWMInputController* pwmInputController, Logger* logger);
    RetractTypes::RetractPosition RetractPosition();
    void ProcessRetractAction(RetractAction* action);
    void ProcessRetractGroupAction(RetractGroupAction* groupAction);
  private:

  PWMInputController* pwmInputController;
  Logger* logger;
  RetractTypes::RetractPosition lastPosition;
  
};
