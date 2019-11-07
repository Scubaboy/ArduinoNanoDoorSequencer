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
  const int RCRetractPWMInputPin = 8;  
}

namespace ServoRawTypes
{
    const int ServoDown = 1000;
    const int ServoUp = 2000;

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
