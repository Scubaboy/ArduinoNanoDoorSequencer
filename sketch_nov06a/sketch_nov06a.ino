#include "RetractController.h"
#include "ServoController.h"
#include "PWMInputController.h"
#include "Types.h"
#include "RetractController.h"
#include "Logger.h"
#include "OpenWheelDoorsGrpAction.h"
#include "CloseWheelDoorsGrpAction.h"
#include "StateController.h"
#include "DeployLandingGearGrpAction.h"
#include "RetractLandingGearGrpAction.h"

StateController stateController;
Logger logger;
ServoController servoController(&logger);
OpenWheelDoorsGrpAction openWheelDoorsGrpAction(&servoController);
CloseWheelDoorsGrpAction closeWheelDoorsGrpAction(&servoController);
DeployLandingGearGrpAction deploylandingGearGrpAction(&servoController);
RetractLandingGearGrpAction retractLandingGearGrpAction(&servoController);
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
        retractController.ProcessRetractGroupAction(&retractLandingGearGrpAction);
        retractController.ProcessRetractGroupAction(&closeWheelDoorsGrpAction);
        stateController.UpdateLastRetractPosition(requestedPosition);
    }
    else if ( requestedPosition == RetractTypes::Down & stateController.RequestLastRetractPosition() != requestedPosition)
    {
        retractController.ProcessRetractGroupAction(&openWheelDoorsGrpAction);
        retractController.ProcessRetractGroupAction(&deploylandingGearGrpAction);
        stateController.UpdateLastRetractPosition(requestedPosition);
    }
  }
}
