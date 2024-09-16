#include <Arduino.h>

#include "Motor.hpp"
#include "pins.h"

Motor left_motor(PWM_L_FWD, PWM_L_BWD);
Motor right_motor(PWM_R_FWD, PWM_R_BWD);

void setup()
{
    pinMode(START, OUTPUT);
    digitalWrite(START, 1);

    Serial.begin(115200);
    while (!Serial)
        ;

    Serial.println("Serial OK");
    left_motor.begin();
    right_motor.begin();
    left_motor.setMovement(50, MOTOR_FORWARD);
}

void loop()
{
    for (uint32_t i = 100; i > 0; i--)
    {
        Serial.printf("PWM at %d%%\n", i);
        left_motor.setMovement(i, MOTOR_FORWARD);
        right_motor.setMovement(i, MOTOR_BACKWARD);
        delay(200);
    }

    Serial.println("Stop");
    left_motor.stop();
    right_motor.stop();
    delay(2000);
}