/**
 * @file NexScrollingText.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef NEXSCROLLINGTEXT_H
#define NEXSCROLLINGTEXT_H

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
#define NEXSCROLLINGTEXT_LOG 1

/**
 * @brief
 *
 */
#define NEXSCROLLINGTEXT_USE_EFFECTS 1

/**
 * @brief
 *
 */
#define NEXSCROLLINGTEXT_USE_ADVANCED_FUNCTIONS 1

/**
 * @brief Scrolling direction:0-Left to Right;1-Right to Left;2-Up to Down;3-Down to Up
 * 
 */
typedef enum _NexScrollingText_direction {
    NEXSCROLLINGTEXT_DIRECTION_LEFT_TO_RIGHT    = 0,
    NEXSCROLLINGTEXT_DIRECTION_RIGHT_TO_LEFT    = 1,
    NEXSCROLLINGTEXT_DIRECTION_UP_TO_DOWN       = 2,
    NEXSCROLLINGTEXT_DIRECTION_DOWN_TO_UP       = 3,
} NexScrollingText_direction;

/**
 * @brief
 *
 */
typedef struct _NexScrollingText
{
    NexObject object;                   // Basic object
    NexWidget widget; // Base widget properties
#if defined(NEXSCROLLINGTEXT_USE_EFFECTS) && (NEXSCROLLINGTEXT_USE_EFFECTS > 0)

#endif
    NexWidget_backgroundFill backgroundFill; // Background fill:0-crop image;1-solid color;2-image;3-transparency
    uint8_t crop_pic_id;                   // Background crop image(must be full screen image. Only if crop image background is selected)
    uint16_t font_color;                   // Font color
    uint8_t font_id;                       // Font id
    uint16_t background_color;             // Background color (only if solid color is defined)
    uint8_t pic_id;                        // Background Image id (must be fullscreen image. Only if background image is selected)
#if defined(NEXSCROLLINGTEXT_USE_ADVANCED_FUNCTIONS) && (NEXSCROLLINGTEXT_USE_ADVANCED_FUNCTIONS > 0)
    NexWidget_horizontalAlign xcen;         // Text Horizontal alignment:0-Left;1-Center;2-Right
    NexWidget_verticalAlign ycen;           // Text Vertical alignment:0-Up;1-Center;2-Down
    bool word_wrap;                         // Wordwrap:0-False;1-True
    NexScrollingText_direction direction;   // Scrolling direction
    uint8_t scrolling_distance;             // Scrolling distance in [ms].(2 to 50)
    uint16_t interval_time;                 // Interval time in ms.(80 to 65535)
    bool enable;                            // Trigger:(0 - Disable, 1 - Enable)

#endif
} NexScrollingText;

/**
 * @brief 
 * 
 * @param nex_scrollingText 
 * @param component_id 
 * @param page_id 
 * @param name 
 * @param effect 
 * @param fill 
 */
void NexScrollingText_init(NexScrollingText *nex_scrollingText, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, NexWidget_backgroundFill fill);

/**
 * @brief Set text attribute of component.
 * @param nex_scrollingText
 * @param text text buffer terminated with '\0'.
 * @return NexReturnCode
 */
NexReturnCode NexScrollingText_setText(NexScrollingText *nex_scrollingText, const char *text);

/**
 * @brief Get text attribute of component.
 * 
 * @param nex_scrollingText 
 * @param text buffer storing text returned.
 * @param len The length of text returned.
 * @return NexReturnCode 
 */
NexReturnCode NexScrollingText_getText(NexScrollingText *nex_scrollingText, char *text, uint16_t *len);

#if defined(NEXSCROLLINGTEXT_USE_ADVANCED_FUNCTIONS) && (NEXSCROLLINGTEXT_USE_ADVANCED_FUNCTIONS > 0)
/**
 * @brief
 *
 * @param nex_scrollingText
 * @param xcen
 * @return NexReturnCode
 */
NexReturnCode NexScrollingText_horizontalJustify(NexScrollingText *nex_scrollingText, NexWidget_horizontalAlign xcen);

/**
 * @brief
 *
 * @param nex_scrollingText
 * @param ycen
 * @return NexReturnCode
 */
NexReturnCode NexScrollingText_verticalJustify(NexScrollingText *nex_scrollingText, NexWidget_verticalAlign ycen);

/**
 * @brief 
 * 
 * @param nex_scrollingText 
 * @param word_wrap 
 * @return NexReturnCode 
 */
NexReturnCode NexScrollingText_setWordWrap(NexScrollingText *nex_scrollingText, bool word_wrap);

/**
 * @brief 
 * 
 * @param nex_scrollingText 
 * @param direction 
 * @return NexReturnCode 
 */
NexReturnCode NexScrollingText_setTextDirection(NexScrollingText *nex_scrollingText, NexScrollingText_direction direction);

/**
 * @brief 
 * 
 * @param nex_scrollingText 
 * @param scrolling_distance 
 * @return NexReturnCode 
 */
NexReturnCode NexScrollingText_setScrollingDistance(NexScrollingText *nex_scrollingText, uint8_t scrolling_distance);

/**
 * @brief 
 * 
 * @param nex_scrollingText 
 * @param interval_time 
 * @return NexReturnCode 
 */
NexReturnCode NexScrollingText_setIntervalTime(NexScrollingText *nex_scrollingText, uint16_t interval_time);

/**
 * @brief 
 * 
 * @param nex_scrollingText 
 * @param enable 
 * @return NexReturnCode 
 */
NexReturnCode NexScrollingText_enableScrolling(NexScrollingText *nex_scrollingText, bool enable);

#endif

/**
 * @brief
 *
 * @param nex_scrollingText
 * @param font_color
 * @return NexReturnCode
 */
NexReturnCode NexScrollingText_setFontColor(NexScrollingText *nex_scrollingText, uint16_t font_color);

/**
 * @brief
 *
 * @param nex_scrollingText
 * @param bg_color
 * @return NexReturnCode
 */
NexReturnCode NexScrollingText_setBackGroundColor(NexScrollingText *nex_scrollingText, uint16_t bg_color);

/**
 * @brief
 *
 * @param nex_scrollingText
 * @param pic_id
 * @return NexReturnCode
 */
NexReturnCode NexScrollingText_setBackGroundImage(NexScrollingText *nex_scrollingText, uint8_t pic_id);

/**
 * @brief
 *
 * @param nex_scrollingText
 * @param crop_image Background crop image id (must be full screen image)
 * @return NexReturnCode
 */
NexReturnCode NexScrollingText_setCropImage(NexScrollingText *nex_scrollingText, uint8_t crop_image);

#ifdef __cplusplus
}
#endif

#endif /*NEXSCROLLINGTEXT_H*/