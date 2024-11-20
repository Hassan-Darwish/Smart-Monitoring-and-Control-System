/*------------------------------------------------------------------------------
 *  Module      : FLAME_SENSOR
 *  File        : flame_sensor.c
 *  Description : Source file for the ATmega32 microcontroller FLAME_SENSOR driver
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------------------------*/

/* Include the flame sensor header and GPIO driver */
#include "flame_sensor.h"
#include "gpio.h"

/*------------------------------------------------------------------------------
 *  Functions and ISR Definitions
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * [Function Name] FLAME_SENSOR_init
 * [Description]   Initializes the flame sensor by configuring the required pin as input.
 *----------------------------------------------------------------------------*/
void FLAME_SENSOR_init(void)
{
    /* Set the pin direction for the flame sensor as input */
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, GPIO_PIN_INPUT);
}

/*------------------------------------------------------------------------------
 * [Function Name] FLAME_SENSOR_getValue
 * [Description]   Reads and returns the current state (logic level) of the flame sensor.
 *----------------------------------------------------------------------------*/
uint8 FLAME_SENSOR_getValue(void)
{
    /* Read the value of the pin where the flame sensor is connected */
	uint8 result = GPIO_readPin(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID);

	return result;  /* Return the logic value (HIGH or LOW) of the sensor */
}
