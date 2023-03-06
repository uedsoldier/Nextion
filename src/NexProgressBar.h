/**
 * @file NexProgressBar.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef NEXPROGRESSBAR_H
#define NEXPROGRESSBAR_H

#ifdef __cplusplus
extern "C"{
#endif

#pragma region Dependencies
#include <stdint.h>
#include <stdbool.h>
#include "NexObject.h"
#include "NexEffect.h"
#include "NexHardware.h"
#include "NexWidget.h"
#pragma endregion

/**
 * @brief 
 * 
*/
#define NEX_PROGRESS_BAR_LOG 1
    
/**
 * @brief 
 * 
*/
#define NEX_PROGRESS_BAR_USE_EFFECTS 1


typedef struct _NexProgressBar{
    NexObject object;                   // Basic object
    NexWidget widget;                   // Base widget proporties
    #if defined(NEX_PROGRESS_BAR_USE_EFFECTS) && (NEX_PROGRESS_BAR_USE_EFFECTS > 0)

    #endif
    NexWidget_backgroundFill backgroundFill; // Background fill:0-crop image;1-solid color;2-image
    uint16_t background_color;          // Background color (only if solid color is defined)
    uint16_t foreground_color;          // Foreground color (only if solid color is defined)
    uint8_t corner_radius;              // Outer filleted corner radius percetage (0-100, 0 is a right angle)
    uint8_t value;                      // Progress value
} NexProgressBar;

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param component_id 
 * @param page_id 
 * @param name 
 * @param effect 
 * @param fill 
 */
void NexProgressBar_init(NexProgressBar *nex_progress_bar, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, NexWidget_backgroundFill fill);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param value 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_setValue(NexProgressBar *nex_progress_bar, uint8_t value);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param value 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_getValue(NexProgressBar *nex_progress_bar, uint8_t *value);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param background_color 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_setBackGroundColor(NexProgressBar *nex_progress_bar, uint16_t background_color);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param foreground_color 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_setForeGroundColor(NexProgressBar *nex_progress_bar, uint16_t foreground_color);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param background_color 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_getBackGroundColor(NexProgressBar *nex_progress_bar, uint16_t *background_color);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param foreground_color 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_getForeGroundColor(NexProgressBar *nex_progress_bar, uint16_t *foreground_color);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param pic_id 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_setBackGroundImage(NexProgressBar *nex_progress_bar, uint8_t pic_id);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param pic_id 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_setForeGroundImage(NexProgressBar *nex_progress_bar, uint8_t pic_id);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param pic_id 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_getBackGroundImage(NexProgressBar *nex_progress_bar, uint8_t *pic_id);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param pic_id 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_getForeGroundImage(NexProgressBar *nex_progress_bar, uint8_t *pic_id);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param corner_radius 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_setCornerRadius(NexProgressBar *nex_progress_bar, uint8_t corner_radius);

/**
 * @brief 
 * 
 * @param nex_progress_bar 
 * @param corner_radius 
 * @return NexReturnCode 
 */
NexReturnCode NexProgressBar_getCornerRadius(NexProgressBar *nex_progress_bar, uint8_t *corner_radius);

#ifdef __cplusplus
}
#endif

#endif /*NEXPROGRESSBAR_H*/