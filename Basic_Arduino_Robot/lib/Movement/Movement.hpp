#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <Arduino.h>
#include "config.h"

#include "Motor.hpp"
#include "DiscCounter.hpp"

class Movement
{
private:
    Motor *_left_motor;
    Motor *_right_motor;

    DiscCounter *_left_counter;
    DiscCounter *_right_counter;
public:
    Movement(Motor *left_motor, Motor *right_motor, DiscCounter *left_counter = nullptr, DiscCounter *right_counter = nullptr);
    ~Movement();

    void attachDiscCounters(DiscCounter *left_counter, DiscCounter *right_counter);
    
};

#endif /* MOVEMENT_H */
