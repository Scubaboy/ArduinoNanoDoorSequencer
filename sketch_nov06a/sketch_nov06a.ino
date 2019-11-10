#include "RetractController.h"
#include "ServoController.h"
#include "PWMInputController.h"
#include "Types.h"
#include "RetractController.h"
#include "Logger.h"
#include "OpenRearWheelDoorsGrpAction.h"
#include "CloseRearWheelDoorsGrpAction.h"

Logger logger;
ServoController servoController(&logger);
OpenRearWheelDoorsGrpAction openRearWheelDoorsGrpAction(&servoController);
CloseRearWheelDoorsGrpAction closeRearWheelDoorsGrpAction(&servoController);
PWMInputController pwmInputController(PWMInputTypes::RCRetractPWMInputPin);
RetractController retractController(&pwmInputController, &logger);
RetractTypes::RetractPosition lastPosition;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  pwmInputController.Init();
  servoController.Init();
  lastPosition = RetractTypes::UnDefined;
}

void loop() {
  // put your main code here, to run repeatedly:
  RetractTypes::RetractPosition requestedPosition = retractController.RetractPosition();
  
  if (requestedPosition == RetractTypes::Up && lastPosition != requestedPosition)
  {
    retractController.ProcessRetractGroupAction(&closeRearWheelDoorsGrpAction);
    lastPosition = requestedPosition;
  }
  else if ( requestedPosition == RetractTypes::Down & lastPosition != requestedPosition)
  {
    retractController.ProcessRetractGroupAction(&openRearWheelDoorsGrpAction);
    lastPosition = requestedPosition;
  }
}
