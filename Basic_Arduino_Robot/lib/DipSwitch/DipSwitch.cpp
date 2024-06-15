#include "DipSwitch.hpp"

/**
 * @brief Construct a new Dip Switch object and initializes pins
 * 
 * @param pins array containing the pins of the switches
 * @param pin_count number of switches = length of _pins_
 */
DipSwitch::DipSwitch(uint32_t pins[], uint32_t pin_count)
{
    _pin_count = pin_count;
    _pins = new uint32_t[_pin_count];

    for (uint32_t i = 0; i < _pin_count; i++)
    {
        _pins[i] = pins[i];
        pinMode(_pins[i], INPUT_PULLUP);
    }
}

/**
 * @brief Destroy the Dip Switch object
 * 
 */
DipSwitch::~DipSwitch()
{
    delete [] _pins;
}

/**
 * @brief Get the state of a switch 
 * (internally, returns the opposite of the real state as the switches are PULLUP)
 * 
 * @param index index of the switch 
 * @return 0 : OFF | 1 : ON | -1 : ERROR  
 */
int8_t DipSwitch::getState(uint32_t index)
{
    if (index >= _pin_count)
    {
        return -1;
    }
    
    return (1 - digitalRead(_pins[index]));
}

/**
 * @brief Get the state of all switches as a binary value. The switch at index 0 corresponds to the LSB.
 * 
 * @return uint32_t 
 */
uint32_t DipSwitch::getStatesAsBinary()
{
    uint32_t res = 0;
    for (uint8_t i = 0; i < _pin_count; i++)
    {
        res += digitalRead(_pins[i]) << i;
    }
    return res;
}