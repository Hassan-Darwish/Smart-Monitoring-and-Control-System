/*------------------------------------------------------------------------------
 *  Module      : FLAME SENSOR Driver
 *  File        : flame_sensor.h
 *  Description : HEADER file for the ATmega32 microcontroller FLAME SENSOR driver
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/

#ifndef FLAME_SENSOR_H_  /* Header guard to prevent multiple inclusions */
#define FLAME_SENSOR_H_

/*------------------------------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------------------------*/

/* Include standard type definitions */
#include "stdtypes.h"

/*------------------------------------------------------------------------------
 *  Pre-Processor Constants and Configurations
 *----------------------------------------------------------------------------*/

/* Define the port and pin where the flame sensor is connected */
#define FLAME_SENSOR_PORT_ID      GPIO_PORTD  /* Port for the flame sensor */
#define FLAME_SENSOR_PIN_ID       GPIO_PIN2    /* Pin for the flame sensor */

/*------------------------------------------------------------------------------
 *  Function Declarations
 *----------------------------------------------------------------------------*/

/* Function to initialize the flame sensor */
void FLAME_SENSOR_init(void);

/* Function to get the current value from the flame sensor */
uint8 FLAME_SENSOR_getValue(void);

#endif /* FLAME_SENSOR_H_ */  /* End of header guard */
