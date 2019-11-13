#include "RetractController.h"
#include "ServoController.h"
#include "PWMInputController.h"
#include "Types.h"
#include "RetractController.h"
#include "Logger.h"
#include "OpenWheelDoorsAction.h"
#include "CloseWheelDoorsAction.h"
#include "StateController.h"
#include "DeployLandingGearAction.h"
#include "RetractLandingGearAction.h"

StateController stateController;
Logger logger;
ServoController servoController(&logger);
OpenWheelDoorsAction openWheelDoorsAction(&servoController);
CloseWheelDoorsAction closeWheelDoorsAction(&servoController);
DeployLandingGearAction deploylandingGearAction(&servoController);
RetractLandingGearAction retractLandingGearAction(&servoController);
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
  
  //Can only start when synched with previous saved state.  
  if (!isSynched)
  {
    isSynched = stateController.IsSynched(requestedPosition);
  }
  else
  {     
    if (requestedPosition == RetractTypes::Up && stateController.RequestLastRetractPosition() != requestedPosition)
    {
        retractController.ProcessRetractAction(&openWheelDoorsAction);
        retractController.ProcessRetractAction(&retractLandingGearAction);
        retractController.ProcessRetractAction(&closeWheelDoorsAction);
        stateController.UpdateLastRetractPosition(requestedPosition);
    }
    else if ( requestedPosition == RetractTypes::Down & stateController.RequestLastRetractPosition() != requestedPosition)
    {
        retractController.ProcessRetractAction(&openWheelDoorsAction);
        retractController.ProcessRetractAction(&deploylandingGearAction);
        retractController.ProcessRetractAction(&closeWheelDoorsAction);
        stateController.UpdateLastRetractPosition(requestedPosition);
    }
  }
}
