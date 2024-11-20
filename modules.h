/*------------------------------------------------------------------------------
 *  Module      : All module headers
 *  File        : modules.h
 *  Description : Header file for mini project three modules
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/

#ifndef MODULES_H_          // Include guard to prevent multiple inclusions
#define MODULES_H_

/*------------------------------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------------------------*/

// Include standard AVR library for input/output operations
#include <avr/io.h>

// Include custom headers for the various modules used in the project
#include "gpio.h"             // GPIO driver for managing general purpose I/O
#include "pwm.h"              // PWM driver for controlling motor speed
#include "adc.h"              // ADC driver for reading analog signals

#include "lcd.h"              // LCD driver for displaying information
#include "dc_motor.h"         // DC motor driver for motor control
#include "led.h"              // LED driver for controlling LEDs
#include "ldr_sensor.h"       // LDR sensor driver for light intensity measurement
#include "flame_sensor.h"     // Flame sensor driver for fire detection
#include "lm35_sensor.h"      // LM35 temperature sensor driver for temperature measurement
#include "buzzer.h"           // Buzzer driver for sound alerts

#include "bit_manipulation.h" // Bit manipulation macros for bitwise operations
#include "stdtypes.h"         // Standard types definitions for uint8, uint16, etc.

#endif /* MODULES_H_ */     // End of include guard
