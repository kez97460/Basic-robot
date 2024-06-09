#ifndef STARTER_H
#define STARTER_H

#include <Arduino.h>
#include "config.h"

enum InputType_t
{
    PULLUP = INPUT_PULLUP,
    PULLDOWN = INPUT_PULLDOWN
};

class Starter
{
private:
    uint32_t _pin;
    InputType_t _input_type;
    bool _not_started_state;
    
public:
    Starter(uint32_t pin, InputType_t input_type = PULLUP, bool default_state = HIGH);
    void attachInterrupt(callback_function_t callback);
    
    bool getState();
};



#endif /* STARTER_H */
