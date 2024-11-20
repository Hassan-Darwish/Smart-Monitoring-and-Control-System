/*------------------------------------------------------------------------------
 *  Module      : main file
 *  File        : main.h
 *  Description : Header file for the main function of the project
 *  Author      : Hassan Darwish
 *----------------------------------------------------------------------------*/

#ifndef MAIN_H_
#define MAIN_H_

/*------------------------------------------------------------------------------
 * Temperature Thresholds
 *----------------------------------------------------------------------------*/
#define TEMP_LOW                                25  /* Lower threshold for temperature (°C) */
#define TEMP_MODERATE                           30  /* Moderate threshold for temperature (°C) */
#define TEMP_HIGH                               35  /* High threshold for temperature (°C) */
#define TEMP_EXTREME                            40  /* Extreme threshold for temperature (°C) */

/*------------------------------------------------------------------------------
 * Light Intensity Thresholds
 *----------------------------------------------------------------------------*/
#define LIGHT_INTENSITY_LOW                     15  /* Lower threshold for light intensity */
#define LIGHT_INTENSITY_MODERATE                50  /* Moderate threshold for light intensity */
#define LIGHT_INTENSITY_HIGH                    70  /* High threshold for light intensity */

/*------------------------------------------------------------------------------
 * DC Motor Speed Constants
 *----------------------------------------------------------------------------*/
#define DC_MOTOR_QUARTERS                       64  /* PWM value for quarter speed of the DC motor */
#define DC_MOTOR_HALF                           128  /* PWM value for half speed of the DC motor */
#define DC_MOTOR_THREE_QUARTERS                 192  /* PWM value for three-quarters speed of the DC motor */
#define DC_MOTOR_FULL                           255  /* PWM value for full speed of the DC motor */

/*------------------------------------------------------------------------------
 * LCD Row and Column Definitions
 *----------------------------------------------------------------------------*/
#define LCD_ROW0                                 0   /* Row 0 on the LCD */
#define LCD_ROW1                                 1   /* Row 1 on the LCD */
#define LCD_LINE_ONE_START                       4   /* Starting position for line one on the LCD */
#define LCD_LINE_TWO_TEMP_RESULT                 5   /* Position for displaying temperature result on line two */
#define LCD_LINE_TWO_LIGHT_RESULT                12  /* Position for displaying light intensity result on line two */

#endif /* MAIN_H_ */
