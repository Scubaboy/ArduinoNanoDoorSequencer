#include "ServoController.h"
#include "Types.h"

ServoController::ServoController(Logger* logger)
{
  this->logger = logger;
}

void ServoController::Init(SystemState::ServoAttributes servoAttributes[6], RetractTypes::RetractPosition lastRetractPosition)
{
  this->servoHwdController[ServoRawTypes::ServoIndex1].attach(ServoRawTypes::Servo1);
  this->servoHwdController[ServoRawTypes::ServoIndex1].write(lastRetractPosition == RetractTypes::Up ? servoAttributes[ServoRawTypes::ServoIndex1].MinAngle : servoAttributes[ServoRawTypes::ServoIndex1].MaxAngle);
  this->servoHwdController[ServoRawTypes::ServoIndex2].attach(ServoRawTypes::Servo2);
  this->servoHwdController[ServoRawTypes::ServoIndex2].write(lastRetractPosition == RetractTypes::Up ? servoAttributes[ServoRawTypes::ServoIndex2].MinAngle : servoAttributes[ServoRawTypes::ServoIndex2].MaxAngle);
  this->servoHwdController[ServoRawTypes::ServoIndex3].attach(ServoRawTypes::Servo3);
  this->servoHwdController[ServoRawTypes::ServoIndex3].write(lastRetractPosition == RetractTypes::Up ? servoAttributes[ServoRawTypes::ServoIndex3].MinAngle : servoAttributes[ServoRawTypes::ServoIndex3].MaxAngle);
  this->servoHwdController[ServoRawTypes::ServoIndex4].attach(ServoRawTypes::Servo4);
  this->servoHwdController[ServoRawTypes::ServoIndex4].write(lastRetractPosition == RetractTypes::Up ? servoAttributes[ServoRawTypes::ServoIndex4].MinAngle : servoAttributes[ServoRawTypes::ServoIndex4].MaxAngle);
  this->servoHwdController[ServoRawTypes::ServoIndex5].attach(ServoRawTypes::Servo5);
  this->servoHwdController[ServoRawTypes::ServoIndex5].write(lastRetractPosition == RetractTypes::Up ? servoAttributes[ServoRawTypes::ServoIndex5].MinAngle : servoAttributes[ServoRawTypes::ServoIndex5].MaxAngle);
  this->servoHwdController[ServoRawTypes::ServoIndex6].attach(ServoRawTypes::Servo6);
  this->servoHwdController[ServoRawTypes::ServoIndex6].write(lastRetractPosition == RetractTypes::Up ? servoAttributes[ServoRawTypes::ServoIndex6].MinAngle : servoAttributes[ServoRawTypes::ServoIndex6].MaxAngle);
  this->isInit = true;  
}

void ServoController::SetServoPosition(ServoRawTypes::ServoIndexIds servo, int newPos)
{
  if (this->isInit)
  {
      this->servoHwdController[servo].write(newPos);
  }
      
}
