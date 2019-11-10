#include "ServoController.h"
#include "Types.h"

ServoController::ServoController(Logger* logger)
{
  this->logger = logger;
}

void ServoController::Init()
{
  this->servoHwdController[ServoRawTypes::ServoIndex1].attach(ServoRawTypes::Servo1);
  this->servoHwdController[ServoRawTypes::ServoIndex1].write(0);
  this->servoHwdController[ServoRawTypes::ServoIndex2].attach(ServoRawTypes::Servo2);
  this->servoHwdController[ServoRawTypes::ServoIndex2].write(0);
  this->servoHwdController[ServoRawTypes::ServoIndex3].attach(ServoRawTypes::Servo3);
  this->servoHwdController[ServoRawTypes::ServoIndex3].write(0);
  this->servoHwdController[ServoRawTypes::ServoIndex4].attach(ServoRawTypes::Servo4);
  this->servoHwdController[ServoRawTypes::ServoIndex4].write(0);
  this->servoHwdController[ServoRawTypes::ServoIndex5].attach(ServoRawTypes::Servo5);
  this->servoHwdController[ServoRawTypes::ServoIndex5].write(0);
  this->servoHwdController[ServoRawTypes::ServoIndex6].attach(ServoRawTypes::Servo6);
  this->servoHwdController[ServoRawTypes::ServoIndex6].write(0);
  this->isInit = true;  
}

void ServoController::SetServoPosition(ServoRawTypes::ServoIndexIds servo, int newPos)
{
  if (this->isInit)
  {
      this->servoHwdController[servo].write(newPos);
  }
      
}
