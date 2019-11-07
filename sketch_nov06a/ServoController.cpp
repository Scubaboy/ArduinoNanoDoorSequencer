#include "ServoController.h"
#include "Types.h"

ServoController::ServoController()
{
  this->servoHwdController.attach(ServoRawTypes::Servo1);
  this->servoHwdController.attach(ServoRawTypes::Servo2);
  this->servoHwdController.attach(ServoRawTypes::Servo1);
  this->servoHwdController.attach(ServoRawTypes::Servo1);
  this->servoHwdController.attach(ServoRawTypes::Servo1);
}

void ServoController::SetServoPosition()
{
    
}
