/*------------------------------------------------------------------------------
 *  Module      : LDR Sensor Driver
 *  File        : ldr_sensor.h
 *  Description : Header file for the ATmega32 microcontroller LDR Sensor driver
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/

#ifndef LDR_SENSOR_H_  /* Include guard to prevent multiple inclusions */
#define LDR_SENSOR_H_

/*------------------------------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------------------------*/

/* Include standard data types header file */
#include "stdtypes.h"

/*------------------------------------------------------------------------------
 *  Pre-Processor Constants and Configurations
 *----------------------------------------------------------------------------*/

/* Define the ADC channel ID for the LDR sensor */
#define LDR_SENSOR_CHANNEL_ID                             0

/* Define the maximum voltage value for the LDR sensor */
#define LDR_SENSOR_MAX_VOLT_VALUE                         2.56

/* Define the maximum light intensity for the LDR sensor */
#define LDR_SENSOR_MAX_LIGHT_INTENSITY                   100

/*------------------------------------------------------------------------------
 *  Function Declarations
 *----------------------------------------------------------------------------*/

/* Function to get the light intensity from the LDR sensor */
uint16 LDR_getLightIntensity(void);

#endif /* LDR_SENSOR_H_ */  /* End of include guard */
