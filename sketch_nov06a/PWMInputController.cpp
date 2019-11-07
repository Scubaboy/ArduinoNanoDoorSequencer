#include "PWMInputController.h"
#include "Arduino.h"

PWMInputController::PWMInputController(int rcInputPin)
{
  this->rcInputPin = rcInputPin;
}

void PWMInputController::Init()
{
    pinMode(this->rcInputPin, INPUT);
}

int PWMInputController::PWMPulseDuration()
{
    return pulseIn(this->rcInputPin, HIGH);
}
