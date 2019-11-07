#include "RearRetractDeploy.h"
#include "Arduino.h"

RearRetractDeploy::RearRetractDeploy(RetractAction* actions, int numberOfActions)
{
  this->actions = actions;
  this->numberOfActions = numberOfActions;
}

void RearRetractDeploy::Execute()
{
  for (int actionIter = 0; actionIter < this->numberOfActions; actionIter++)
  {
    this->actions->Execute();
    this->actions++;
  }

  delay(this->actionDelay);
}
