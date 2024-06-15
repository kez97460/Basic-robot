#include "Motor.hpp"

void Motor::update()
{
    if (_timer_fwd == nullptr || _timer_bwd == nullptr)
    {
        return; // TODO: ERROR VALUE ?? 
    }

    if (_direction == FORWARD)
    {
        _timer_bwd->setPWM(_channel_bwd, _pwm_bwd_pin, _frequency_hz, 0);
        _timer_fwd->setPWM(_channel_fwd, _pwm_fwd_pin, _frequency_hz, _duty_cycle_percent);
    }
    else // _direction == BACKWARD
    {
        _timer_bwd->setPWM(_channel_bwd, _pwm_bwd_pin, _frequency_hz, _duty_cycle_percent);
        _timer_fwd->setPWM(_channel_fwd, _pwm_fwd_pin, _frequency_hz, 0); 
    }
}

Motor::Motor(pin_t dir, pin_t pwm)
{
    _frequency_hz = 10000;
    _duty_cycle_percent = 0;
}

Motor::~Motor()
{
    end();
}

void Motor::begin()
{
    TIM_TypeDef *instance_fwd = (TIM_TypeDef *) pinmap_peripheral(digitalPinToPinName(_pwm_fwd_pin), PinMap_PWM);
    TIM_TypeDef *instance_bwd = (TIM_TypeDef *) pinmap_peripheral(digitalPinToPinName(_pwm_bwd_pin), PinMap_PWM);
    
    _channel_fwd = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(_pwm_fwd_pin), PinMap_PWM));
    _channel_bwd = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(_pwm_bwd_pin), PinMap_PWM));

    _timer_fwd = new HardwareTimer(instance_fwd);
    if (instance_bwd != instance_fwd)
    {
        _timer_bwd = new HardwareTimer(instance_bwd);
    }
    else 
    {
        _timer_bwd = _timer_fwd; // Same timer for both : no need for 2 separate objects, just copy pointer value
    }
    
    update();
}

void Motor::end()
{
    if(_timer_bwd)
    {
        delete _timer_bwd;
    }
    if(_timer_fwd)
    {
        delete _timer_fwd;
    }
}

void Motor::setPwmFrequency(uint32_t frequency_hz)
{
    _frequency_hz = frequency_hz;
    update();
}

void Motor::setDirection(MotorDirection_t dir)
{
    _direction = dir;
    update();
}

void Motor::setDutyCycle(uint8_t duty_cycle_percent)
{
    _duty_cycle_percent = duty_cycle_percent;
    update();
}

void Motor::setMovement(MotorDirection_t dir = FORWARD, uint8_t duty_cycle_percent)
{
    setDirection(dir);
    setPwmFrequency(duty_cycle_percent);
}

void Motor::stop()
{
    setDutyCycle(0);
}