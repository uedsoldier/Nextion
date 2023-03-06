/**
 * @file NexObject.h
 * @author José Roberto Parra Trewartha (uedsoldier1990@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NEXOBJECT_H
#define NEXOBJECT_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 
 * 
 */
typedef enum _NexObject_type{
    NEXOBJECT_TYPE_PAGE            = 121,
    NEXOBJECT_TYPE_TEXT            = 116,
    NEXOBJECT_TYPE_SCROLLING_TEXT  = 55,
    NEXOBJECT_TYPE_NUMBER          = 54,
    NEXOBJECT_TYPE_XFLOAT          = 59,
    NEXOBJECT_TYPE_BUTTON          = 98,
    NEXOBJECT_TYPE_PROGRESS_BAR    = 106,
    NEXOBJECT_TYPE_PICTURE         = 112,
    NEXOBJECT_TYPE_CROP            = 113,
    NEXOBJECT_TYPE_HOTSPOT         = 109,
    NEXOBJECT_TYPE_TOUCHCAP        = 5,
    NEXOBJECT_TYPE_GAUGE           = 122,
    NEXOBJECT_TYPE_WAVEFORM        = 0,
    NEXOBJECT_TYPE_SLIDER          = 1,
    NEXOBJECT_TYPE_TIMER           = 51,
    NEXOBJECT_TYPE_VARIABLE        = 52,
    NEXOBJECT_TYPE_DUAL_STATE_BUTTON = 53,
    NEXOBJECT_TYPE_CHECKBOX        = 56,
    NEXOBJECT_TYPE_RADIO           = 57,
    NEXOBJECT_TYPE_QR_CODE         = 58,
    NEXOBJECT_TYPE_SWITCH          = 67,
    NEXOBJECT_TYPE_COMBO_BOX       = 61,
    NEXOBJECT_TYPE_TEXT_SELECT     = 68,
    NEXOBJECT_TYPE_SL_TEXT         = 62,
    NEXOBJECT_TYPE_DATA_RECORD     = 66,
    NEXOBJECT_TYPE_FILE_BROWSER    = 65,
    NEXOBJECT_TYPE_FILE_STREAM     = 63,
    NEXOBJECT_TYPE_GMOV            = 2,
    NEXOBJECT_TYPE_VIDEO           = 3,
    NEXOBJECT_TYPE_AUDIO           = 4,
    NEXOBJECT_TYPE_EXTERNAL_PICTURE = 60,
    //...

} NexObject_type;

/**
 * @brief 
 * 
 */
typedef enum _NexObject_scope{
    LOCAL = 0,
    GLOBAL = 1,
} NexObject_scope;

/**
 * @brief 
 * 
 */
typedef void (*NexTouch_eventCallback)(void *ptr);


/**
 * @brief Basic parameters of Nextion objects
 * 
 */
typedef struct _NexObject
{
    NexObject_type type; // Component type (read-only at runtime)
    uint8_t page_id;            // Page ID (read-only at runtime)
    uint8_t id;                 // Component ID (read-only at runtime)
    char objname[16];           // Component unique name (read-only at runtime)
    NexObject_scope vscope;     // Variable scope(local-visible in current page, global-visible  in all pages):0-local;1-global

    NexTouch_eventCallback cb_push;    // Callback for push event
    void *cbpush_ptr;           // Pointer for eventual push callback data
    NexTouch_eventCallback cb_pop;     // Callback for pop event
    void *cbpop_ptr;            // Pointer for eventual pop callback data    
} NexObject;

/**
 * @brief 
 * 
 * @param object 
 * @param type 
 * @param page_id 
 * @param component_id 
 * @param name 
 */
void NexObject_init(NexObject *object, NexObject_type type, uint8_t page_id, uint8_t component_id, const char *name);

#ifdef __cplusplus
}
#endif

#endif /*NEXOBJECT_H*/