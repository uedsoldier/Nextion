/**
 * @file NexText.h
 * @author José Roberto Parra Trewartha (uedsoldier1990@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef NEXTEXT_H
#define NEXTEXT_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "NexHardware.h"
#include "NexWidget.h"

/**
 * @brief 
 * 
*/
#define NEX_TEXT_USE_EFFECTS 0

/**
 * @brief Background fill:0-crop image;1-solid color;2-image;3-transparency
 */
typedef enum _Nex_textBackgroundFill{
    NEX_TEXT_BACKGROUND_FILL_CROP_IMAGE     = 0,
    NEX_TEXT_BACKGROUND_FILL_SOLID_COLOR    = 1,
    NEX_TEXT_BACKGROUND_FILL_IMAGE          = 2,  
    NEX_TEXT_BACKGROUND_FILL_TRANSPARENCY   = 3,  
} Nex_textBackgroundFill;


/**
 * @brief 
 * 
 */
typedef struct _NexText{
    NexWidget widget;                   // Base widget proporties
    #if defined(NEX_TEXT_USE_EFFECTS) && (NEX_TEXT_USE_EFFECTS > 0)
    
    #endif 
    Nex_textBackgroundFill backgroundFill;  // Background fill:0-crop image;1-solid color;2-image;3-transparency
    uint8_t crop_pic_id;                    // Background crop image(must be full screen image. Only if crop image background is selected)
    uint16_t background_color;              // Background color (only if solid color is defined)
    uint8_t pic_id;                         // Background Image id (must be fullscreen image. Only if background image is selected)

    
} NexText;

void NexText_init(NexText *nex_text,uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect );
NexReturnCode NexText_setText(NexText *nex_text, const char *text);
uint16_t NexText_getText(NexText *nex_text, char *text, uint16_t len);
// NexReturnCode NexText_setBackGroundSolidColor(NexText *nex_text, uint16_t bg_color );
// NexReturnCode NexText_setBackGroundImage(NexText *nex_text);

#ifdef __cplusplus
}
#endif

#endif /*NEXTEXT_H*/