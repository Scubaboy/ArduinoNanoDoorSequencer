#include "RetractController.h"
#include "ServoController.h"
#include "PWMInputController.h"
#include "Types.h"
#include "RetractController.h"
#include "Logger.h"
#include "OpenRearWheelDoorsGrpAction.h"

Logger logger;
ServoController servoController;
OpenRearWheelDoorsGrpAction openRearWheelDoorsGrpAction(&servoController);
PWMInputController pwmInputController(PWMInputTypes::RCRetractPWMInputPin);
RetractController retractController(&pwmInputController, &logger);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  pwmInputController.Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  RetractTypes::RetractPosition requestedPosition = retractController.RetractPosition();
  
  if (requestedPosition == RetractTypes::Up)
  {
    retractController.ProcessRetractGroupAction(&openRearWheelDoorsGrpAction);
  }
  else if ( requestedPosition == RetractTypes::Down)
  {
    retractController.ProcessRetractGroupAction(&openRearWheelDoorsGrpAction);
  }
}
