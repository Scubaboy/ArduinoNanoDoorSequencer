#pragma once
#include "PWMInputController.h"
#include "Types.h"
#include "RetractAction.h"
#include "Logger.h"

class RetractController
{
  public:
    RetractController (PWMInputController* pwmInputController, Logger* logger);
    RetractTypes::RetractPosition RetractPosition();
    void ProcessRetractAction(RetractAction* action);
  private:

  PWMInputController* pwmInputController;
  Logger* logger;
  RetractTypes::RetractPosition lastPosition;
  
};
