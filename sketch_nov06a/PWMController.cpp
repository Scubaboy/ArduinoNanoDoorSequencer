#include "PWMController.h"
#include "Arduino.h"

PWMController::PWMController(int rcInputPin, int outputPins[6])
{
  this->rcInputPin = rcInputPin;
  this->outputPins[0] = outputPins[0];
  this->outputPins[1] = outputPins[1];
  this->outputPins[2] = outputPins[2];
  this->outputPins[3] = outputPins[3];
  this->outputPins[4] = outputPins[4];
  this->outputPins[5] = outputPins[4];
}

void PWMController::Init()
{
    pinMode(this->rcInputPin, INPUT);
}

int PWMController::PWMPulseDuration()
{
    return pulseIn(this->rcInputPin, HIGH);
}
