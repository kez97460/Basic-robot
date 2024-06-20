#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>
#include <Servo.h>

#include "config.h"

#include "Movement.hpp"
#include "DipSwitch.hpp"
/// TODO: add ToF
/// TODO: add screen
/// TODO: add HC-06

class Robot
{
private:
    
public:
    Robot();
    ~Robot();
};

#endif /* ROBOT_H */
