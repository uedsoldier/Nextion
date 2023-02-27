/**
 * @file NexGpio.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NEXGPIO_H
#define NEXGPIO_H

#ifdef __cplusplus
extern "C"
{
#endif

#pragma region Dependencies
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#pragma endregion


typedef enum _NexGpio_mode{
    NEXGPIO_MODE_PULLUP_INPUT       = 0,
    NEXGPIO_MODE_INPUT_BINDING      = 1,    // binding triggers component Press on falling edge and component Release on rising edge
    NEXGPIO_MODE_PUSHPULL_OUTPUT    = 2,
    NEXGPIO_MODE_PWM                = 3,    // For PWM mode, set duty cycle before cfgpio: ie: pwm4=20 for 20% duty
    NEXGPIO_MODE_OPEN_DRAIN         = 4,
} NexGpio_mode;

/**
 * @brief 
 * 
 * @param gpio_num 
 * @param mode 
 * @param bound_component 
 * @return NexReturnCode 
 */
NexReturnCode NexGpio_config(uint8_t gpio_num, NexGpio_mode mode, const char *bound_component);

/**
 * @brief 
 * 
 * @param gpio_num 
 * @param state 
 * @return NexReturnCode 
 */
NexReturnCode NexGpio_setOutput(uint8_t gpio_num, bool state);


/**
 * @brief Sets PWM Duty Cycle. Value in percentage. min 0, max 100, default 50.
 * 
 * @param gpio_num 
 * @param duty 
 * @return NexReturnCode 
 */
NexReturnCode NexGpio_setPwmDuty(uint8_t gpio_num, uint8_t duty);

/**
 * @brief Sets PWM Frequency. Value is in [Hz]. min value 1 [Hz], max value 65535 [Hz]. default 1000 [Hz]
 * All PWM output is unified to only one Frequency, no independent individual settings are allowed.
 * 
 * @param gpio_num 
 * @param freq 
 * @return NexReturnCode 
 */
NexReturnCode NexGpio_setPwmFrequency(uint8_t gpio_num, uint16_t freq);

#ifdef __cplusplus
}
#endif

#endif /*NEXGPIO_H*/