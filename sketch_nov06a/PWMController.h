#pragma once

class PWMController
{
  public:
    void Init();
    PWMController(int rcInputPin);
    int PWMPulseDuration();
  private:
    int rcInputPin;
};
