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

namespace ServoRawTypes
{
    const int ServoDown = 1000;
    const int ServoUp = 2000;
}
