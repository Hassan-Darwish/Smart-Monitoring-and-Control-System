/*------------------------------------------------------------------------------
 *  Module      : ADC Driver
 *  File        : adc.c
 *  Description : Source file for the ATmega32 microcontroller adc driver
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------------------------*/

#include <avr/io.h>                     /* Include the standard AVR IO definitions */
#include "bit_manipulation.h"            /* Custom bit manipulation macros */
#include "adc.h"                         /* Header file for ADC driver */

/*------------------------------------------------------------------------------
 *  Functions and ISR Definitions
 *----------------------------------------------------------------------------*/

/*
 * Function: ADC_init
 * ----------------------------
 *   Initializes the ADC module with voltage reference and prescaler settings.
 *   The function configures the ADC voltage reference based on a predefined mode.
 *   It also sets the ADC prescaler and enables the ADC.
 */
void ADC_init(void)
{
    /* Configure the voltage reference selection based on ADC_VOLT_REFERENCE_MODE */
#if ADC_VOLT_REFERENCE_MODE == 0
    CLEAR_BIT(ADMUX, REFS0);             /* Select AREF, internal Vref turned off */
    CLEAR_BIT(ADMUX, REFS1);
#elif ADC_VOLT_REFERENCE_MODE == 1
    SET_BIT(ADMUX, REFS0);               /* AVCC with external capacitor at AREF pin */
    CLEAR_BIT(ADMUX, REFS1);
#elif ADC_VOLT_REFERENCE_MODE == 2
    CLEAR_BIT(ADMUX, REFS0);             /* Reserved */
    SET_BIT(ADMUX, REFS1);
#elif ADC_VOLT_REFERENCE_MODE == 3
    SET_BIT(ADMUX, REFS0);               /* Internal 2.56V Voltage Reference with external capacitor at AREF pin */
    SET_BIT(ADMUX, REFS1);
#endif

    /* Configure ADC data register to right-adjust the result (ADLAR = 0) */
    CLEAR_BIT(ADMUX, ADLAR);

    /* Enable ADC by setting the ADEN bit in ADCSRA register */
    SET_BIT(ADCSRA, ADEN);

    /* Set ADC prescaler to 128 (ADPS2:ADPS0 = 111) for accurate sampling frequency */
    SET_BIT(ADCSRA, ADPS0);
    SET_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS2);
}

/*
 * Function: ADC_readChannel
 * ----------------------------
 *   Reads the analog value from a specific ADC channel and returns the digital result.
 *   The function ensures that the channel number is within valid bounds and starts
 *   the ADC conversion.
 *
 *   channel_num: The ADC channel to be read (from 0 to ADC_CHANNELS_NUMBER).
 *
 *   returns: The 10-bit digital value corresponding to the analog input on the selected channel.
 */
uint16 ADC_readChannel(uint8 channel_num)
{
    /* Mask the channel number to ensure it's within the valid range */
    channel_num &= ADC_CHANNELS_NUMBER;

    /* Clear the previous channel selection and set the new channel */
    ADMUX = (ADMUX & 0xE0) | (channel_num & 0x1F);

    /* Start ADC conversion by setting the ADSC bit */
    SET_BIT(ADCSRA, ADSC);

    /* Wait for the conversion to complete (ADIF flag will be set when done) */
    while(IS_BIT_CLEAR(ADCSRA, ADIF));

    /* Clear the ADIF flag by writing a '1' to it */
    SET_BIT(ADCSRA, ADIF);

    /* Return the result from the ADC data register (ADCL and ADCH) */
    return ADCW;
}
