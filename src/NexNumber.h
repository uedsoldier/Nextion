/**
 * @file NexNumber.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef NEXNUMBER_H
#define NEXNUMBER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "NexHardware.h"
#include "NexWidget.h"

/**
 * @brief
 *
 */
#define NEXNUMBER_LOG 1

/**
 * @brief
 *
 */
#define NEXNUMBER_USE_EFFECTS 0

/**
 * @brief
 *
 */
#define NEXNUMBER_USE_ADVANCED_FUNCTIONS 1


typedef enum _NexNumber_format{
    NEXNUMBER_FORMAT_DECIMAL    = 0,
    NEXNUMBER_FORMAT_CURRENCY   = 1,
    NEXNUMBER_FORMAT_HEX        = 2,
} NexNumber_format;

/**
 * @brief
 *
 */
typedef struct _NexNumber
{
    NexObject object;                   // Basic object
    NexWidget widget; // Base widget properties
#if defined(NEXTEXT_USE_EFFECTS) && (NEXTEXT_USE_EFFECTS > 0)

#endif
    NexWidget_backgroundFill backgroundFill;    // Background fill:0-crop image;1-solid color;2-image;3-transparency
    uint8_t crop_pic_id;                        // Background crop image(must be full screen image. Only if crop image background is selected)
    uint16_t font_color;                        // Font color
    uint8_t font_id;                            // Font id
    uint16_t background_color;                  // Background color (only if solid color is defined)
    uint8_t pic_id;                             // Background Image id (must be fullscreen image. Only if background image is selected)
    uint8_t length;                             //Show length(0-auto,Max-15)
    NexNumber_format format;                             // Format type:0-Decimal;1-Currency;2-Hex
#if defined(NEXNUMBER_USE_ADVANCED_FUNCTIONS) && (NEXNUMBER_USE_ADVANCED_FUNCTIONS > 0)
    NexWidget_horizontalAlign xcen;             // Text Horizontal alignment:0-Left;1-Center;2-Right
    NexWidget_verticalAlign ycen;               // Text Vertical alignment:0-Up;1-Center;2-Down
    bool word_wrap;                             // Wordwrap:0-False;1-True   
#endif
} NexNumber;

void NexNumber_init(NexNumber *nex_number, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, NexWidget_backgroundFill fill);

NexReturnCode NexNumber_setValue(NexNumber *nex_number, uint32_t value);

NexReturnCode NexNumber_getValue(NexNumber *nex_number, uint32_t *value);

NexReturnCode NexNumber_setLength(NexNumber *nex_number, uint8_t length);

#if defined(NEXTEXT_USE_ADVANCED_FUNCTIONS) && (NEXTEXT_USE_ADVANCED_FUNCTIONS > 0)

NexReturnCode NexNumber_horizontalJustify(NexNumber *nex_number, NexWidget_horizontalAlign xcen);

NexReturnCode NexNumber_verticalJustify(NexNumber *nex_number, NexWidget_verticalAlign ycen);

NexReturnCode NexNumber_setWordWrap(NexNumber *nex_number, bool word_wrap);

#endif

NexReturnCode NexNumber_setFontColor(NexNumber *nex_number, uint16_t font_color);

NexReturnCode NexNumber_setBackGroundColor(NexNumber *nex_number, uint16_t bg_color);

NexReturnCode NexNumber_setBackGroundImage(NexNumber *nex_number, uint8_t pic_id);

NexReturnCode NexNumber_setCropImage(NexNumber *nex_number, uint8_t crop_image);

NexReturnCode NexNumber_setFormat(NexNumber *nex_number, NexNumber_format format);

#ifdef __cplusplus
}
#endif

#endif /*NEXNUMBER_H*/