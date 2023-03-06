/**
 * @file NexSlider.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NEXSLIDER_H
#define NEXSLIDER_H

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
#define NEX_SLIDER_LOG 1
    
/**
 * @brief 
 * 
*/
#define NEX_SLIDER_USE_EFFECTS 1


typedef struct _NexSlider{
    NexObject object;                   // Basic object
    NexWidget widget;                   // Base widget proporties
    #if defined(NEX_SLIDER_USE_EFFECTS) && (NEX_SLIDER_USE_EFFECTS > 0)

    #endif
    NexWidget_backgroundFill backgroundFill; // Background fill:0-crop image;1-solid color;2-image
    uint16_t background_color;          // Background color (only if solid color is defined)
    uint16_t foreground_color;          // Foreground color (only if solid color is defined)
    uint16_t cursor_color;
    uint8_t corner_radius;              // Outer filleted corner radius percetage (0-100, 0 is a right angle)
    uint16_t value;                      // Current value
    uint16_t min_value;                     // Min Val(0-65535)
    uint16_t max_value;                     // Max Val(0-65535)
} NexSlider;

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param component_id 
 * @param page_id 
 * @param name 
 * @param effect 
 * @param fill 
 */
void NexSlider_init(NexSlider *nex_slider, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, NexWidget_backgroundFill fill);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param value 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_setValue(NexSlider *nex_slider, uint8_t value);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param value 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_getValue(NexSlider *nex_slider, uint8_t *value);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param background_color 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_setBackGroundColor(NexSlider *nex_slider, uint16_t background_color);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param foreground_color 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_setForeGroundColor(NexSlider *nex_slider, uint16_t foreground_color);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param cursor_color 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_setCursorColor(NexSlider *nex_slider, uint16_t cursor_color);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param background_color 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_getBackGroundColor(NexSlider *nex_slider, uint16_t *background_color);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param foreground_color 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_getForeGroundColor(NexSlider *nex_slider, uint16_t *foreground_color);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param cursor_color 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_getCursorColor(NexSlider *nex_slider, uint16_t *cursor_color);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param pic_id 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_setBackGroundImage(NexSlider *nex_slider, uint8_t pic_id);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param pic_id 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_setForeGroundImage(NexSlider *nex_slider, uint8_t pic_id);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param pic_id 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_getBackGroundImage(NexSlider *nex_slider, uint8_t *pic_id);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param pic_id 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_getForeGroundImage(NexSlider *nex_slider, uint8_t *pic_id);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param corner_radius 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_setCornerRadius(NexSlider *nex_slider, uint8_t corner_radius);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param corner_radius 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_getCornerRadius(NexSlider *nex_slider, uint8_t *corner_radius);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param cursor_height 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_setCursorHeight(NexSlider *nex_slider, uint8_t cursor_height);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param cursor_height 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_getCursorHeight(NexSlider *nex_slider, uint8_t *cursor_height);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param background_width_percentage 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_setBackgroundWidthPercentage(NexSlider *nex_slider, uint8_t background_width_percentage);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param background_width_percentage 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_getBackgroundWidthPercentage(NexSlider *nex_slider, uint8_t *background_width_percentage);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param min_value 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_setMinValue(NexSlider *nex_slider, uint16_t min_value);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param min_value 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_getMinValue(NexSlider *nex_slider, uint16_t *min_value);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param max_value 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_setMaxValue(NexSlider *nex_slider, uint16_t max_value);

/**
 * @brief 
 * 
 * @param nex_slider 
 * @param max_value 
 * @return NexReturnCode 
 */
NexReturnCode NexSlider_getMaxValue(NexSlider *nex_slider, uint16_t *max_value);

#ifdef __cplusplus
}
#endif

#endif /*NEXSLIDER_H*/