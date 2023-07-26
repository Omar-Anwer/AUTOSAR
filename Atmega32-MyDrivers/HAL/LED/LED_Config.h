/*
 * LED_Config.h
 *
 */

#ifndef HAL_LED_LED_CONFIG_H_
#define HAL_LED_LED_CONFIG_H_

/*--------------------------------------------------------------------------------------------*/
/*   SELECT MICROCONTROLERS PINS   */
/*--------------------------------------------------------------------------------------------*/
#define LED_YELLOW_PIN      DIO_PA6_PIN
#define LED_BLUE_PIN        DIO_PA5_PIN
#define LED_GREEN_PIN       DIO_PA4_PIN
#define LED_RED_PIN         DIO_PB7_PIN

/*--------------------------------------------------------------------------------------------*/
/*   SELECT LED BLINKING TIME IN MILLI SECONDS   */
/*--------------------------------------------------------------------------------------------*/
#define LED_BLINKING_TIME_MS         125

#endif /* HAL_LED_LED_CONFIG_H_ */
