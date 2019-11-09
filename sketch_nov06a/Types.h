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

    enum ServoOutputPins 
    {
      Servo1 = 2,
      Servo2 = 3,
      Servo3 = 4,
      Servo4 = 5,
      Servo5 = 6,
      Servo6 = 7
    };
}
