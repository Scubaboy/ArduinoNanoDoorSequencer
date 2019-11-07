#pragma once
#include "RetractGroupAction.h"
#include "RetractAction.h"

class RearRetractDeploy : public RetractGroupAction
{
  public:
    RearRetractDeploy(RetractAction* actions, int numberOfActions);
    void Execute();
  private:
    RetractAction* actions;
    int numberOfActions;
    const int actionDelay = 1000;
};
