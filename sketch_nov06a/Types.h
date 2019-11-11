#pragma once

namespace RetractTypes
{
  enum RetractPosition {Up, Down, UnDefined};

  enum Action {
    OpenRightRearWheelDoor, 
    CloseRightRearWheelDoor,
    OpenLeftRearWheelDoor, 
    CloseLeftRearWheelDoor,
    OpenFrontWheelDoor, 
    CloseFrontWheelDoor
    };
}

namespace PWMInputTypes
{
  const int RCRetractPWMInputPin = 2;  
}

namespace ServoRawTypes
{
    const int ServoDown = 980;
    const int ServoUp = 1800;

    enum ServoIndexIds
    {
      ServoIndex1 = 0,
      ServoIndex2 = 1,
      ServoIndex3 = 2,
      ServoIndex4 = 3,
      ServoIndex5 = 4,
      ServoIndex6 = 5
    };
    
    enum ServoOutputPins 
    {
      Servo1 = 3,
      Servo2 = 4,
      Servo3 = 5,
      Servo4 = 6,
      Servo5 = 7,
      Servo6 = 8
    };
}

namespace SystemState
{
  struct ServoAttributes
  {
    int MaxAngle;
    int MinAngle;
    int DegPerSecond;
  };
  
  struct State
  {
    float Version;
    RetractTypes::RetractPosition LastRetractPosition;
    ServoAttributes servoAttributes[6];
  };
}
