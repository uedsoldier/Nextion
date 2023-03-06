/**
 * @file NexButton.h
 * @author José Roberto Parra Trewartha (uedsoldier1990@gmail.com)
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
#include "NexObject.h"
#include "NexWidget.h"


/**
 * @brief
 *
 */
#define NEXBUTTON_LOG 1

/**
 * @brief
 *
 */
#define NEXBUTTON_USE_EFFECTS 0

/**
 * @brief
 *
 */
#define NEXBUTTON_USE_ADVANCED_FUNCTIONS 0

/**
 * @brief 
 * 
 */
typedef struct _NexButton{
    NexObject object;                   // Basic object
    NexWidget widget; // Base widget properties
    #if defined(NEXBUTTON_USE_EFFECTS) && (NEXBUTTON_USE_EFFECTS > 0)

#endif
    NexWidget_backgroundFill backgroundFill; // Background fill:0-crop image;1-solid color;2-image;3-transparency
    uint8_t crop_pic_id;                // Background crop image(must be full screen image. Only if crop image background is selected)
    uint16_t font_color;                // Font color
    uint16_t press_font_color;          // Press font color
    uint8_t font_id;                    // Font id
    uint16_t background_color;          // Background color (only if solid color is defined)
    uint16_t press_background_color;    // Press background color (only if solid color is defined)
    uint8_t pic_id;                     // Background Image id (must be fullscreen image. Only if background image is selected)
    #if defined(NEXBUTTON_USE_ADVANCED_FUNCTIONS) && (NEXBUTTON_USE_ADVANCED_FUNCTIONS > 0)
    NexButton_horizontalAlign xcen; // Text Horizontal alignment:0-Left;1-Center;2-Right
    NexButton_verticalAlign ycen;   // Text Vertical alignment:0-Up;1-Center;2-Down
    bool word_wrap;               // Wordwrap:0-False;1-True
#endif
} NexButton;

/**
 * @brief 
 * 
 * @param nex_button 
 * @param component_id 
 * @param page_id 
 * @param name 
 * @param effect 
 * @param fill 
 */
void NexButton_init(NexButton *nex_button, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect,NexWidget_backgroundFill fill);

/**
 * @brief Set text attribute of component.
 * @param nex_button
 * @param text text buffer terminated with '\0'.
 * @return NexReturnCode
 */
NexReturnCode NexButton_setText(NexButton *nex_button, const char *text);

/**
 * @brief Get text attribute of component.
 * @param nex_button
 * @param text buffer storing text returned.
 * @param len length of buffer.
 * @return uint16_t The real length of text returned.
 */
uint16_t NexButton_getText(NexButton *nex_button, char *text, uint16_t len);

#if defined(NexButton_USE_ADVANCED_FUNCTIONS) && (NexButton_USE_ADVANCED_FUNCTIONS > 0)
/**
 * @brief
 *
 * @param nex_button
 * @param xcen
 * @return NexReturnCode
 */
NexReturnCode NexButton_horizontalJustify(NexButton *nex_button, NexButton_horizontalAlign xcen);

/**
 * @brief
 *
 * @param nex_button
 * @param ycen
 * @return NexReturnCode
 */
NexReturnCode NexButton_verticalJustify(NexButton *nex_button, NexButton_verticalAlign ycen);

/**
 * @brief 
 * 
 * @param nex_button 
 * @param word_wrap 
 * @return NexReturnCode 
 */
NexReturnCode NexButton_setWordWrap(NexButton *nex_button, bool word_wrap);

#endif

/**
 * @brief
 *
 * @param nex_button
 * @param font_color
 * @return NexReturnCode
 */
NexReturnCode NexButton_setFontColor(NexButton *nex_button, uint16_t font_color);

/**
 * @brief 
 * 
 * @param nex_button 
 * @param press_font_color 
 * @return NexReturnCode 
 */
NexReturnCode NexButton_setPressFontColor(NexButton *nex_button, uint16_t press_font_color);

/**
 * @brief
 *
 * @param nex_button
 * @param bg_color
 * @return NexReturnCode
 */
NexReturnCode NexButton_setBackGroundColor(NexButton *nex_button, uint16_t bg_color);

/**
 * @brief 
 * 
 * @param nex_button 
 * @param press_bg_color 
 * @return NexReturnCode 
 */
NexReturnCode NexButton_setPressBackGroundColor(NexButton *nex_button, uint16_t press_bg_color);

/**
 * @brief
 *
 * @param nex_button
 * @param pic_id
 * @return NexReturnCode
 */
NexReturnCode NexButton_setBackGroundImage(NexButton *nex_button, uint8_t pic_id);

/**
 * @brief
 *
 * @param nex_button
 * @param crop_image Background crop image id (must be full screen image)
 * @return NexReturnCode
 */
NexReturnCode NexButton_setCropImage(NexButton *nex_button, uint8_t crop_image);

#ifdef __cplusplus
}
#endif

#endif /*NEXBUTTON_H*/
