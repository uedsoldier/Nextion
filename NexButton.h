/**
 * @file NexButton.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NEXBUTTON_H
#define NEXBUTTON_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "NexTouch.h"
#include "NexHardware.h"

typedef enum _Nextion_return_code{
    NEXTION_INVALID_INSTRUCTION = 0x00,
    NEXTION_INSTRUCTION_SUCCESFUL

} Nextion_return_code;

uint8_t NexButton_getText(NexObject *button, char *buffer, uint16_t len);
uint8_t NexButton_setText(NexObject *button, char *buffer);

uint32_t NexButton_getBackGroundColor(NexObject *button, uint32_t *number);
uint8_t NexButton_setBackGroundColor(NexObject *button, uint32_t *number);

uint32_t NexButton_getPressBackGroundColor(NexObject *button, uint32_t *number);
uint8_t NexButton_setPressBackGroundColor(NexObject *button, uint32_t *number);

uint32_t NexButton_getFontColor(NexObject *button, uint32_t *number);
uint8_t NexButton_setFontColor(NexObject *button, uint32_t *number);

uint32_t NexButton_getPressFontColor(NexObject *button, uint32_t *number);
uint8_t NexButton_setPressFontColor(NexObject *button, uint32_t *number);

uint32_t NexButton_getFont(NexObject *button, uint32_t *number);
uint8_t NexButton_setFont(NexObject *button, uint32_t number);


#ifdef __cplusplus
}
#endif


#endif /*NEXBUTTON_H*/
