#include "Starter.h"

Starter::Starter(uint32_t pin, InputType_t input_type, bool default_state)
{
    _pin = pin;
    _input_type = input_type;
    _not_started_state = default_state;

    pinMode(_pin, _input_type);
}

void Starter::attachInterrupt(callback_function_t callback)
{
    
}
