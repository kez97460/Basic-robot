/**
 * @file pins.h
 * @author Kezia Marcou
 * @brief Pinout of the MCU. Defines custom pin names used everywhere. 
 * Do not change the names of the macros. 
 */
#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

// UART2 (USB link to PC)
#define UART2_RX A2
#define UART2_TX A7

// Motors
#define PWM_L D0
#define PWM_R D1
#define DIR_L D9
#define DIR_R D10

// ToF sensors
#define XSDN1 D2 
#define XSDN2 D3 

// UART1 
#define UART1_RX D4 
#define UART1_TX D5

// Servo
#define PWM_SERVO D6 

// I2C
#define I2C3_SDA D12
#define I2C3_SCL A6

// Switches
#define SW0 A0
#define SW1 A1 
#define SW2 A3
#define SW3 A4 
#define START D13

#endif /* PINS_H */
