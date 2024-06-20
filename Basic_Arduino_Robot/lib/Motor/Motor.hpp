#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include "config.h"

enum MotorDirection_t
{
    MOTOR_FORWARD,
    MOTOR_BACKWARD
};

class Motor
{
private:
    // Pins
    pin_t _pwm_fwd_pin;
    pin_t _pwm_bwd_pin;

    // Timer(s)
    HardwareTimer *_timer_fwd;
    HardwareTimer *_timer_bwd;
    uint32_t _channel_fwd;
    uint32_t _channel_bwd;

    // PWM Control
    uint32_t _frequency_hz;
    uint8_t _duty_cycle_percent;
    MotorDirection_t _direction;

    void update();
    
public:
    Motor(pin_t pwm_forward = 0, pin_t pwm_backward = 0);
    ~Motor();

    void begin(pin_t pwm_forward, pin_t pwm_backward);
    void begin();
    void end();

    void setPwmFrequency(uint32_t frequency_hz);

    void setDirection(MotorDirection_t dir);
    void setDutyCycle(uint8_t duty_cycle_percent = 0);
    void setMovement(uint8_t duty_cycle_percent, MotorDirection_t dir = MOTOR_FORWARD);
    void stop();
};

#endif /* MOTOR_H */
