#pragma once

class PWMInputController
{
  public:
    void Init();
    PWMInputController(int rcInputPin);
    int PWMPulseDuration();
  private:
    int rcInputPin;
};
