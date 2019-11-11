#include "RetractController.h"
#include "ServoController.h"
#include "PWMInputController.h"
#include "Types.h"
#include "RetractController.h"
#include "Logger.h"
#include "OpenRearWheelDoorsGrpAction.h"
#include "CloseRearWheelDoorsGrpAction.h"
#include "StateController.h"

StateController stateController;
Logger logger;
ServoController servoController(&logger);
OpenRearWheelDoorsGrpAction openRearWheelDoorsGrpAction(&servoController);
CloseRearWheelDoorsGrpAction closeRearWheelDoorsGrpAction(&servoController);
PWMInputController pwmInputController(PWMInputTypes::RCRetractPWMInputPin);
RetractController retractController(&pwmInputController, &logger);
RetractTypes::RetractPosition lastPosition;
bool isSynched;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  pwmInputController.Init();
  stateController.Init();
  servoController.Init(stateController.GetServoAttributes(), stateController.RequestLastRetractPosition());
  lastPosition = RetractTypes::UnDefined;
  isSynched = false;
}

void loop() {

  // put your main code here, to run repeatedly:
  RetractTypes::RetractPosition requestedPosition = retractController.RetractPosition();

  if (!isSynched)
  {
    isSynched = stateController.IsSynched(requestedPosition);
  }
  else
  { 
    if (requestedPosition == RetractTypes::Up && stateController.RequestLastRetractPosition() != requestedPosition)
    {
        retractController.ProcessRetractGroupAction(&closeRearWheelDoorsGrpAction);
        stateController.UpdateLastRetractPosition(requestedPosition);
    }
    else if ( requestedPosition == RetractTypes::Down & stateController.RequestLastRetractPosition() != requestedPosition)
    {
        retractController.ProcessRetractGroupAction(&openRearWheelDoorsGrpAction);
        stateController.UpdateLastRetractPosition(requestedPosition);
    }
  }
}
