/*------------------------------------------------------------------------------
 *  Module      : ADC Driver
 *  File        : adc.h
 *  Description : Source file for the ATmega32 microcontroller ADC driver
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/

#ifndef ADC_H_
#define ADC_H_

/*------------------------------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------------------------*/

/*
 * Include necessary libraries:
 * - avr/io.h: This provides definitions for the IO registers of AVR microcontrollers.
 * - stdtypes.h: This file is assumed to contain standard data types definitions like uint8, uint16, etc.
 */
#include <avr/io.h>
#include "stdtypes.h"

/*------------------------------------------------------------------------------
 *  Pre-Processor Constants and Configurations
 *----------------------------------------------------------------------------*/

/*
 * ADC_MAXIMUM_VALUE:
 * Defines the maximum 10-bit value that can be read from the ADC (0-1023).
 */
#define ADC_MAXIMUM_VALUE                                    1023

/*
 * ADC_REF_VOLT_VALUE:
 * Defines the reference voltage used by the ADC for conversions.
 * For this configuration, it's set to 2.56V.
 */
#define ADC_REF_VOLT_VALUE                                   2.56

/*
 * ADC_VOLT_REFERENCE_MODE:
 * Specifies the reference voltage mode to be used.
 * Mode 3: Internal 2.56V reference with external capacitor at AREF pin.
 */
#define ADC_VOLT_REFERENCE_MODE                              3

/*
 * ADC_CHANNELS_NUMBER:
 * Defines the maximum number of ADC channels (from 0 to 7) for this setup.
 */
#define ADC_CHANNELS_NUMBER                                  0x07

/*------------------------------------------------------------------------------
 *  Function Declarations
 *----------------------------------------------------------------------------*/

/*
 * ADC_init:
 * Initializes the ADC by setting up the voltage reference, prescaler, and enabling the ADC.
 */
void ADC_init(void);

/*
 * ADC_readChannel:
 * Reads the analog value from the specified ADC channel and returns a 10-bit digital result.
 *
 * channel_num: The number of the ADC channel to read from.
 *
 * returns: The converted 10-bit digital value from the ADC.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
