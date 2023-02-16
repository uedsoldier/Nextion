/**
 * @file NexWidget.h
 * @author José Roberto Parra Trewartha (uedsoldier1990@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef NEXWIDGET_H
#define NEXWIDGET_H

#ifdef __cplusplus
extern "C"{
#endif

#pragma region Dependencies
#include <stdint.h>
#include <stdbool.h>
#include "NexObject.h"
#include "NexEffect.h"
#pragma endregion

/**
 * @brief Display style:0-flat;1-border;2-3D_Down;3-3D_Up
 * 
 */
typedef enum _Nex_widgetStyle{
    NEX_WIDGET_STYLE_FLAT       = 0,
    NEX_WIDGET_STYLE_BORDER     = 1,
    NEX_WIDGET_STYLE_3D_DOWN    = 2,
    NEX_WIDGET_STYLE_3D_UP      = 3,
    NEX_WIDGET_STYLE_NONE       = -1
} Nex_widgetStyle;


/**
 * @brief 
 * Horizontal alignment:0-Left;1-Center;2-Right
 */
typedef enum _Nex_horizontalAlignment{
    NEX_ALIGNMENT_LEFT    = 0,
    NEX_ALIGNMENT_CENTER  = 1,
    NEX_ALIGNMENT_RIGHT   = 2
} Nex_horizontalAlignment;

/**
 * @brief 
 * Vertical alignment:0-Up;1-Center;2-Down
 */
typedef enum _Nex_verticalAlignment{
    NEX_ALIGNMENT_UP        = 0,
    NEX_ALIGNMENT_CENTER    = 1,
    NEX_ALIGNMENT_DOWN      = 2
} Nex_verticalAlignment;

/**
 * @brief 
 * 
 */
typedef struct _NexWidget{
    NexObject object;           // Basic object
    bool drag;                  // Drag available:0-no;1-yes
    int8_t aph;                 // Opaqueness(0-127)
    Nex_effect effect;          // Load effect
    uint16_t x;                 // X coordinate 
    uint16_t y;                 // Y coordinate 
    uint16_t w;                 // Width (read-only at runtime)
    uint16_t h;                 // Height (read-only at runtime)


} NexWidget;


NexReturnCode NexWidget_init(NexWidget *nex_widget);

#ifdef __cplusplus
}
#endif

#endif /*NEXWIDGET_H*/