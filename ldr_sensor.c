/*------------------------------------------------------------------------------
 *  Module      : LDR Sensor Driver
 *  File        : ldr_sensor.c
 *  Description : Source file for the ATmega32 microcontroller LDR sensor driver
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------------------------*/

/* Include header file for the LDR sensor driver */
#include "ldr_sensor.h"

/* Include header file for the ADC driver */
#include "adc.h"

/*------------------------------------------------------------------------------
 *  Functions and ISR Definitions
 *----------------------------------------------------------------------------*/

/* Function to get the light intensity from the LDR sensor */
uint16 LDR_getLightIntensity(void)
{
	uint16 intensity_value = 0; /* Variable to store the calculated light intensity */
	uint16 adc_value = 0;       /* Variable to store the raw ADC value */

	/* Read the ADC value from the specified channel for the LDR sensor */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the intensity value based on the ADC value and conversion factors */
	intensity_value = (uint16)(((uint32)adc_value * LDR_SENSOR_MAX_LIGHT_INTENSITY * ADC_REF_VOLT_VALUE) /
	                            (ADC_MAXIMUM_VALUE * LDR_SENSOR_MAX_VOLT_VALUE));

	return intensity_value; /* Return the calculated light intensity */
}
