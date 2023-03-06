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
#define NEXTEXT_LOG 1

/**
 * @brief
 *
 */
#define NEXTEXT_USE_EFFECTS 0

/**
 * @brief
 *
 */
#define NEXTEXT_USE_ADVANCED_FUNCTIONS 1

/**
 * @brief
 *
 */
typedef struct _NexText
{
    NexObject object;                   // Basic object
    NexWidget widget; // Base widget properties
#if defined(NEXTEXT_USE_EFFECTS) && (NEXTEXT_USE_EFFECTS > 0)

#endif
    NexWidget_backgroundFill backgroundFill; // Background fill:0-crop image;1-solid color;2-image;3-transparency
    uint8_t crop_pic_id;                   // Background crop image(must be full screen image. Only if crop image background is selected)
    uint16_t font_color;                   // Font color
    uint8_t font_id;                       // Font id
    uint16_t background_color;             // Background color (only if solid color is defined)
    uint8_t pic_id;                        // Background Image id (must be fullscreen image. Only if background image is selected)
#if defined(NEXTEXT_USE_ADVANCED_FUNCTIONS) && (NEXTEXT_USE_ADVANCED_FUNCTIONS > 0)
    NexWidget_horizontalAlign xcen; // Text Horizontal alignment:0-Left;1-Center;2-Right
    NexWidget_verticalAlign ycen;   // Text Vertical alignment:0-Up;1-Center;2-Down
    bool word_wrap;               // Wordwrap:0-False;1-True
    bool is_password;             // Input type:0-Character;1-Password
#endif
} NexText;

/**
 * @brief 
 * 
 * @param nex_text 
 * @param component_id 
 * @param page_id 
 * @param name 
 * @param effect 
 * @param fill 
 */
void NexText_init(NexText *nex_text, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, NexWidget_backgroundFill fill);

/**
 * @brief Set text attribute of component.
 * @param nex_text
 * @param text text buffer terminated with '\0'.
 * @return NexReturnCode
 */
NexReturnCode NexText_setText(NexText *nex_text, const char *text);

/**
 * @brief Get text attribute of component.
 * @param nex_text
 * @param text buffer storing text returned.
 * @param len length of buffer.
 * @return size_t 
 */
NexReturnCode NexText_getText(NexText *nex_text, char *text, size_t *len);

#if defined(NEXTEXT_USE_ADVANCED_FUNCTIONS) && (NEXTEXT_USE_ADVANCED_FUNCTIONS > 0)
/**
 * @brief
 *
 * @param nex_text
 * @param xcen
 * @return NexReturnCode
 */
NexReturnCode NexText_horizontalJustify(NexText *nex_text, NexWidget_horizontalAlign xcen);

/**
 * @brief
 *
 * @param nex_text
 * @param ycen
 * @return NexReturnCode
 */
NexReturnCode NexText_verticalJustify(NexText *nex_text, NexWidget_verticalAlign ycen);

/**
 * @brief 
 * 
 * @param nex_text 
 * @param word_wrap 
 * @return NexReturnCode 
 */
NexReturnCode NexText_setWordWrap(NexText *nex_text, bool word_wrap);

/**
 * @brief 
 * 
 * @param nex_text 
 * @param as_password 
 * @return NexReturnCode 
 */
NexReturnCode NexText_setAsPassword(NexText *nex_text, bool as_password);

#endif

/**
 * @brief
 *
 * @param nex_text
 * @param font_color
 * @return NexReturnCode
 */
NexReturnCode NexText_setFontColor(NexText *nex_text, uint16_t font_color);

/**
 * @brief
 *
 * @param nex_text
 * @param bg_color
 * @return NexReturnCode
 */
NexReturnCode NexText_setBackGroundColor(NexText *nex_text, uint16_t bg_color);

/**
 * @brief
 *
 * @param nex_text
 * @param pic_id
 * @return NexReturnCode
 */
NexReturnCode NexText_setBackGroundImage(NexText *nex_text, uint8_t pic_id);

/**
 * @brief
 *
 * @param nex_text
 * @param crop_image Background crop image id (must be full screen image)
 * @return NexReturnCode
 */
NexReturnCode NexText_setCropImage(NexText *nex_text, uint8_t crop_image);

#ifdef __cplusplus
}
#endif

#endif /*NEXTEXT_H*/