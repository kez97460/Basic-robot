#ifndef DIPSWITCH_H
#define DIPSWITCH_H

#include <Arduino.h>
#include "config.h"

class DipSwitch
{
private:
    uint32_t *_pins;
    uint32_t _pin_count;
public:
    DipSwitch(uint32_t pins[], uint32_t pin_count = 1);
    ~DipSwitch();

    int8_t getState(uint32_t index);
    uint32_t getStatesAsBinary();
};


#endif /* DIPSWITCH_H */
