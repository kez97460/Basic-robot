#ifndef DISCCOUNTER_H
#define DISCCOUNTER_H

#include <Arduino.h>
#include "config.h"



class DiscCounter
{
private:
    // Index de chaque instance de la classe. 
    static uint8_t max_insance_index;
    uint8_t _instance_index;

    uint32_t _count;

public:
    DiscCounter();
    DiscCounter(pin_t pin);
    ~DiscCounter();

    void begin();
    void begin(pin_t pin);
    void end();

    uint32_t getCount();
};

#endif /* DISCCOUNTER_H */
