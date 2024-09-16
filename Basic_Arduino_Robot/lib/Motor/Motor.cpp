#include "Motor.hpp"

/**
 * @brief update the output to the motor to account for changes in the variables
 * 
 */
void Motor::update()
{
    if (_timer_fwd == nullptr || _timer_bwd == nullptr)
    {
        return; // TODO: ERROR VALUE ?? 
    }

    if (_direction == MOTOR_FORWARD)
    {
        _timer_bwd->setPWM(_channel_bwd, _pwm_bwd_pin, _frequency_hz, 0);
        _timer_fwd->setPWM(_channel_fwd, _pwm_fwd_pin, _frequency_hz, _duty_cycle_percent);
    }
    else // _direction == MOTOR_BACKWARD
    {
        _timer_bwd->setPWM(_channel_bwd, _pwm_bwd_pin, _frequency_hz, _duty_cycle_percent);
        _timer_fwd->setPWM(_channel_fwd, _pwm_fwd_pin, _frequency_hz, 0); 
    }
}

/**
 * @brief Construct a new Motor:: Motor object using the associated pins
 * 
 * @param pwm_fwd pin corresponding to forward rotation
 * @param pwm_bwd pin corresponding to backward rotation
 */
Motor::Motor(pin_t pwm_fwd, pin_t pwm_bwd)
{
    _frequency_hz = 10000;
    _duty_cycle_percent = 0;
    _pwm_bwd_pin = pwm_bwd;
    _pwm_fwd_pin = pwm_fwd;
}

Motor::~Motor()
{
    end();
}

/**
 * @brief Initialize all values to begin using the motor
 * 
 */
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

/**
 * @brief Set the pins and initialize all values to begin using the motor
 * 
 * @param pwm_forward pin corresponding to forward rotation
 * @param pwm_backward pin corresponding to backward rotation
 */
void Motor::begin(pin_t pwm_forward, pin_t pwm_backward)
{
    _pwm_fwd_pin = pwm_forward;
    _pwm_bwd_pin = pwm_backward;

    begin();
}

/**
 * @brief De-initialize the motor
 * 
 */
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

/**
 * @brief Set the frequency used for the PWM
 * 
 * @param frequency_hz frequency in Hz (default : 10kHz)
 */
void Motor::setPwmFrequency(uint32_t frequency_hz)
{
    _frequency_hz = frequency_hz;
    update();
}

/**
 * @brief Set the direction of the movement
 * 
 * @param dir MOTOR_FORWARD or MOTOR_BACKWARD (default: MOTOR_FORWARD)
 */
void Motor::setDirection(MotorDirection_t dir)
{
    _direction = dir;
    update();
}

/**
 * @brief Set duty cycle for the motor
 * 
 * @param duty_cycle_percent duty cycle in percentage (default: 0), motor may not move with low values...
 */
void Motor::setDutyCycle(uint8_t duty_cycle_percent)
{
    _duty_cycle_percent = duty_cycle_percent;
    update();
}

/**
 * @brief Sets both direction and duty cycle
 * 
 * @param duty_cycle_percent duty cycle in percentage (default: 0), motor may not move with low values...
 * @param dir MOTOR_FORWARD or MOTOR_BACKWARD (default: MOTOR_FORWARD)
 */
void Motor::setMovement(uint8_t duty_cycle_percent, MotorDirection_t dir)
{
    setDirection(dir);
    setDutyCycle(duty_cycle_percent);
}

/**
 * @brief Stop the motor (equivalent to setDutyCycle(0) or setDutyCycle())
 * 
 */
void Motor::stop()
{
    setDutyCycle(0);
}