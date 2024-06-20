#include <Arduino.h>

#include "Motor.hpp"
#include "pins.h"

Motor left_motor(PWM_L_FWD, PWM_L_BWD);
Motor right_motor(PWM_R_FWD, PWM_R_BWD);

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;

    left_motor.begin();
    right_motor.begin();
}

void loop()
{
    for (uint32_t i = 0; i <= 100; i++)
    {
        Serial.printf("PWM at %d%%\n", i);
        left_motor.setMovement(i, MOTOR_FORWARD);
        right_motor.setMovement(i, MOTOR_BACKWARD);
        delay(200);
    }
}