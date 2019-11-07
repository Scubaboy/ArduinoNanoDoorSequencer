#include "PWMController.h"
#include "Arduino.h"
#include <Servo.h>

PWMController::PWMController(int rcInputPin)
{
  this->rcInputPin = rcInputPin;
}

void PWMController::Init()
{
    pinMode(this->rcInputPin, INPUT);
}

int PWMController::PWMPulseDuration()
{
    return pulseIn(this->rcInputPin, HIGH);
}
