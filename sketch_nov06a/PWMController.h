#pragma once

class PWMController
{
  public:
    void Init();
    PWMController(int rcInputPin, int outputPins[6]);
    int PWMPulseDuration();
    
    
  private:
    int rcInputPin;
    int outputPins[6];
};
