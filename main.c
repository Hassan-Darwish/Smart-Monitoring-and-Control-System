/*------------------------------------------------------------------------------
 *  Module      : main file
 *  File        : main.c
 *  Description : Source file for the main function of the project
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------------------------*/

#include "modules.h" /*  contains headers of each driver  */
#include "util/delay.h" /* Include delay library for timing functions */
#include "main.h" /* Include the main header file for project-specific definitions */

/*------------------------------------------------------------------------------
 *  Functions and ISR Definitions
 *----------------------------------------------------------------------------*/


int main(void)
{

	/*  modules initialization  */
	ADC_init(); /* Initialize the ADC module for analog input */
	LCD_init(); /* Initialize the LCD for displaying information */
	LED_init(); /* Initialize the LEDs for visual feedback */
	BUZZER_init(); /* Initialize the buzzer for sound alerts */
	DC_MOTOR_init(); /* Initialize the DC motor driver */
	FLAME_SENSOR_init(); /* Initialize the flame sensor for detecting fire */

	for(;;) /* Infinite loop to continuously monitor sensor values */
	{
		uint8 flame_sensor_result = FLAME_SENSOR_getValue(); /* Get the current value from the flame sensor */
		if(flame_sensor_result == LOGIC_HIGH) /* If a flame is detected */
		{
			LCD_clearScreen(); /* Clear the LCD display */
			LCD_displayString("Critical alert!"); /* Display a critical alert message */

			BUZZER_on(); /* Activate the buzzer for an alert sound */

			while(flame_sensor_result == LOGIC_HIGH) /* Wait until the flame is no longer detected */
			{
				flame_sensor_result = FLAME_SENSOR_getValue(); /* Update flame sensor result */
			}
		}
		else /* If no flame is detected */
		{
			LCD_clearScreen(); /* Clear the LCD display */
			BUZZER_off(); /* Turn off the buzzer */

    		LCD_displayStringRowColumn(LCD_ROW0, LCD_LINE_TWO_TEMP_RESULT,"FAN is OFF"); /* Display fan status */
    		LCD_displayStringRowColumn(LCD_ROW1, LCD_ROW0,"Temp="); /* Display temperature label */
    		LCD_displayString("C "); /* Display temperature unit */

    		LCD_displayStringRowColumn(LCD_ROW1, 8,"LDR="); /* Display LDR label */
    		LCD_displayStringRowColumn(LCD_ROW1, 15,"%"); /* Display percentage unit for LDR */

			while(flame_sensor_result == LOGIC_LOW) /* While no flame is detected */
			{
				uint16 light_intensity_result = LDR_getLightIntensity(); /* Get light intensity from the LDR */
				uint8 temperature_result = LM35_getTemperature(); /* Get temperature from the LM35 sensor */

				if(light_intensity_result >= 100) /* If light intensity is above a threshold */
				{
					LCD_moveCursor(1,LCD_LINE_TWO_LIGHT_RESULT); /* Move cursor to display light intensity */
					LCD_integerToString(light_intensity_result); /* Display light intensity value */
				}
				else /* If light intensity is below the threshold */
				{
					LCD_moveCursor(LCD_ROW1,LCD_LINE_TWO_LIGHT_RESULT); /* Move cursor to display light intensity */
					LCD_integerToString(light_intensity_result); /* Display light intensity value */
		            LCD_displayCharacter(' '); /* Clear potential leftover characters */
				}

				if(temperature_result >= 100) /* If temperature is above 100 degrees */
				{
					LCD_moveCursor(LCD_ROW1,LCD_LINE_TWO_TEMP_RESULT); /* Move cursor to display temperature */
					LCD_integerToString(temperature_result); /* Display temperature value */
				}
				else /* If temperature is below 100 degrees */
				{
					LCD_moveCursor(LCD_ROW1,LCD_LINE_TWO_TEMP_RESULT); /* Move cursor to display temperature */
					LCD_integerToString(temperature_result); /* Display temperature value */
		            LCD_displayCharacter(' '); /* Clear potential leftover characters */
				}

				/* Determine LED states based on light intensity */
				if(light_intensity_result < LIGHT_INTENSITY_LOW) /* Very low light intensity */
				{
					LED_on(LED_RED); /* Turn on red LED */
					LED_on(LED_GREEN); /* Turn on green LED */
					LED_on(LED_BLUE); /* Turn on blue LED */
				}
				else if(light_intensity_result >= LIGHT_INTENSITY_LOW && light_intensity_result < LIGHT_INTENSITY_MODERATE) /* Moderate light intensity */
				{
					LED_on(LED_RED); /* Turn on red LED */
					LED_on(LED_GREEN); /* Turn on green LED */
					LED_off(LED_BLUE); /* Turn off blue LED */
				}
				else if(light_intensity_result >= LIGHT_INTENSITY_MODERATE && light_intensity_result < LIGHT_INTENSITY_HIGH) /* High light intensity */
				{
					LED_on(LED_RED); /* Turn on red LED */
					LED_off(LED_GREEN); /* Turn off green LED */
					LED_off(LED_BLUE); /* Turn off blue LED */
				}
				else if(light_intensity_result > LIGHT_INTENSITY_HIGH) /* Very high light intensity */
				{
					LED_off(LED_RED); /* Turn off red LED */
					LED_off(LED_GREEN); /* Turn off green LED */
					LED_off(LED_BLUE); /* Turn off blue LED */
				}

				/* Control fan motor based on temperature */
				if(temperature_result < TEMP_LOW) /* If temperature is low */
				{
					LCD_displayStringRowColumn(LCD_ROW0,LCD_LINE_TWO_TEMP_RESULT,"FAN is OFF"); /* Display fan status */
		            LCD_displayCharacter(' '); /* Clear potential leftover characters */
					DC_MOTOR_rotate(STOP,LCD_ROW0); /* Stop the motor */
				}
				else if(temperature_result >= TEMP_LOW && temperature_result < TEMP_MODERATE) /* If temperature is moderate */
				{
					LCD_displayStringRowColumn(LCD_ROW0,LCD_LINE_TWO_TEMP_RESULT,"FAN is ON"); /* Display fan status */
		            LCD_displayCharacter(' '); /* Clear potential leftover characters */
					DC_MOTOR_rotate(CLOCKWISE,DC_MOTOR_QUARTERS); /* Set motor speed to quarter */
				}
				else if(temperature_result >= TEMP_MODERATE && temperature_result < TEMP_HIGH) /* If temperature is high */
				{
					LCD_displayStringRowColumn(LCD_ROW0,LCD_LINE_TWO_TEMP_RESULT,"FAN is ON"); /* Display fan status */
		            LCD_displayCharacter(' '); /* Clear potential leftover characters */
					DC_MOTOR_rotate(CLOCKWISE,DC_MOTOR_HALF); /* Set motor speed to half */
				}
				else if(temperature_result >= TEMP_HIGH && temperature_result < TEMP_EXTREME) /* If temperature is very high */
				{
					LCD_displayStringRowColumn(LCD_ROW0,LCD_LINE_TWO_TEMP_RESULT,"FAN is ON"); /* Display fan status */
		            LCD_displayCharacter(' '); /* Clear potential leftover characters */
					DC_MOTOR_rotate(CLOCKWISE,DC_MOTOR_THREE_QUARTERS); /* Set motor speed to three-quarters */
				}
				else if(temperature_result >= TEMP_EXTREME) /* If temperature is extreme */
				{
					LCD_displayStringRowColumn(LCD_ROW0,LCD_LINE_TWO_TEMP_RESULT,"FAN is ON"); /* Display fan status */
		            LCD_displayCharacter(' '); /* Clear potential leftover characters */
					DC_MOTOR_rotate(CLOCKWISE,DC_MOTOR_FULL); /* Set motor speed to full */
				}

				flame_sensor_result = FLAME_SENSOR_getValue(); /* Update flame sensor result */
			}
		}
	}
}
