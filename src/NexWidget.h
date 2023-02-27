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
#include "NexHardware.h"
#pragma endregion

/**
 * @brief Display style:0-flat;1-border;2-3D_Down;3-3D_Up
 * 
 */
typedef enum _Nex_widgetStyle{
    NEXWIDGET_STYLE_FLAT       = 0,
    NEXWIDGET_STYLE_BORDER     = 1,
    NEXWIDGET_STYLE_3D_DOWN    = 2,
    NEXWIDGET_STYLE_3D_UP      = 3,
    NEXWIDGET_STYLE_NONE       = -1
} Nex_widgetStyle;

/**
 * @brief Background fill:0-crop image;1-solid color;2-image;3-transparency
 */
typedef enum _NexWidget_backgroundFill
{
    NEXWIDGET_BACKGROUND_FILL_CROP_IMAGE = 0,
    NEXWIDGET_BACKGROUND_FILL_SOLID_COLOR = 1,
    NEXWIDGET_BACKGROUND_FILL_IMAGE = 2,
    NEXWIDGET_BACKGROUND_FILL_TRANSPARENCY = 3,
} NexWidget_backgroundFill;

/**
 * @brief Horizontal alignment:0-Left;1-Center;2-Right
 */
typedef enum _NexWidget_horizontalAlign
{
    NEXWIDGET_HORIZONTAL_ALIGN_LEFT = 0,
    NEXWIDGET_HORIZONTAL_ALIGN_CENTER = 1,
    NEXWIDGET_HORIZONTAL_ALIGN_RIGHT = 2,
} NexWidget_horizontalAlign;

/**
 * @brief Vertical alignment:0-Up;1-Center;2-Down
 */
typedef enum _NexWidget_verticalAlign
{
    NEXWIDGET_VERTICAL_ALIGN_UP = 0,
    NEXWIDGET_VERTICAL_ALIGN_CENTER = 1,
    NEXWIDGET_VERTICAL_ALIGN_DOWN = 2,
} NexWidget_verticalAlign;

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

/**
 * @brief 
 * @param nex_widget
 * @param component_id
 * @param page_id
 * @param name
 */
void NexWidget_init(NexWidget *nex_widget, uint8_t component_id, uint8_t page_id, const char *name);

#ifdef __cplusplus
}
#endif

#endif /*NEXWIDGET_H*/