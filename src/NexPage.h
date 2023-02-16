/**
 * @file NexPage.h
 * @author José Roberto Parra Trewartha (uedsoldier1990@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NEXPAGE_H
#define NEXPAGE_H

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
#define NEX_PAGE_USE_EFFECTS 0

/**
 * @brief Background fill:0-no background;1-solid color;2-image
 */
typedef enum _Nex_pageBackgroundFill{
    NEXPAGE_NO_BACKGROUND               = 0,
    NEXPAGE_BACKGROUND_FILL_SOLID_COLOR = 1,
    NEXPAGE_BACKGROUND_FILL_IMAGE       = 2,  
} Nex_pageBackgroundFill;


typedef enum _Nex_scrollDirection{
    NEX_SCROLL_UP, NEX_SCROLL_DOWN, NEX_SCROLL_LEFT, NEX_SCROLL_RIGHT 
} Nex_scrollDirection;

/**
 * @brief 
 * 
 */
typedef struct _NexPage{
    NexWidget widget;                   // Base widget proporties
    #if defined(NEX_PAGE_USE_EFFECTS) 
    #if(NEX_PAGE_USE_EFFECTS > 0)
    uint8_t scroll_up;                   // Scroll up page ID (No scrolling page:255)
    uint8_t scroll_down;                 // Scroll down page ID (No scrolling page:255)
    uint8_t scroll_left;                 // Scroll left page ID (No scrolling page:255)
    uint8_t scroll_right;                // Scroll right page ID (No scrolling page:255)
    #endif
    #if(NEX_PAGE_USE_EFFECTS > 1)
    uint8_t effect_priority;    // Effect priority(run high value first,max:100)   
    uint16_t effect_time;       // effect time(min 150 [ms], max 65535 [ms])
    #endif
    #endif 
    Nex_pageBackgroundFill background_fill; // Background fill:0-no background;1-solid color;2-image (read-only at runtime)
    uint16_t background_color;           // Background color (only if solid color is defined)
    uint8_t pic_id;                     // Background Image id (must be fullscreen image. Only if background image is selected)   

    //
    
    
} NexPage;

void NexPage_init(NexPage *nex_page,uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect );
NexReturnCode NexPage_show(NexPage *nex_page);
NexReturnCode NexPage_setBackGroundSolidColor(NexPage *nex_page, uint16_t bg_color );
NexReturnCode NexPage_setBackGroundImage(NexPage *nex_page);

#if defined(NEX_PAGE_USE_EFFECTS) && (NEX_PAGE_USE_EFFECTS > 0)
NexReturnCode NexPage_setScrollPage(NexPage *nex_page, Nex_scrollDirection direction, uint8_t page_id);
#endif




#ifdef __cplusplus
}
#endif

#endif /*NEXPAGE_H*/