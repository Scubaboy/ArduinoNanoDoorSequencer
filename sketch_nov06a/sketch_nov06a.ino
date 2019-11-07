#include "RetractController.h"
#include "ServoController.h"
#include "PWMInputController.h"
#include "Types.h"
#include "RetractController.h"
#include "Logger.h"

ServoController servoController;
PWMInputController pwmInputController(PWMInputTypes::RCRetractPWMInputPin);
RetractController retractController(&pwmInputController);
Logger logger;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  RetractTypes::RetractPosition requestedPosition = retractController.RetractPosition();
  
  if (requestedPosition == RetractTypes::Up)
  {
    logger.Log("Retract Up");
  }
  else if ( requestedPosition == RetractTypes::Down)
  {
    logger.Log("Retract Down");
  }

  
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay (100);
  
}
