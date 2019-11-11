#pragma once
#include "Types.h"

class StateController
{
  public:
    void Init();
    RetractTypes::RetractPosition RequestLastRetractPosition();
    void UpdateLastRetractPosition(RetractTypes::RetractPosition retractPosition);
    bool IsSynched(RetractTypes::RetractPosition retractPosition);
  private:
     SystemState::State currentState; 
     const int baseAddress = 0;
     bool isInit;
};
