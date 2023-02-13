/**
 * @file NexObject.h
 * @author your name (you@domain.com)
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

typedef void (*NexTouchEventCb)(void *ptr);

/**
 * @brief 
 * 
 */
typedef enum _NexObject_type{
    PAGE            = 121,
    TEXT            = 116,
    SCROLLING_TEXT  = 55,
    NUMBER          = 54,
    XFLOAT          = 59,
    BUTTON          = 98,
    PROGRESS_BAR    = 106,
    PICTURE         = 112,
    CROP            = 113,
    HOTSPOT         = 109,
    TOUCHCAP        = 5,
    GAUGE           = 122,
    WAVEFORM        = 0,
    SLIDER          = 1,
    TIMER           = 51,
    VARIABLE        = 52,
    DUAL_STATE_BUTTON = 53,
    CHECKBOX        = 56,
    RADIO           = 57,
    QR_CODE         = 58,
    SWITCH          = 67,
    COMBO_BOX       = 61,
    TEXT_SELECT     = 68,
    SL_TEXT         = 62,
    DATA_RECORD     = 66,
    FILE_BROWSER    = 65,
    FILE_STREAM     = 63,
    GMOV            = 2,
    VIDEO           = 3,
    AUDIO           = 4,
    EXTERNAL_PICTURE = 60,
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
 * @brief Basic parameters of Nextion objects
 * 
 */
typedef struct _NexObject
{
    static NexObject_type type; // Component type (read-only at runtime)
    uint8_t page_id;            // Page ID (read-only at runtime)
    uint8_t id;                 // Component ID (read-only at runtime)
    char objname[16];           // Component unique name (read-only at runtime)
    NexObject_scope vscope;     // Variable scope(local-visible in current page, global-visible  in all pages):0-local;1-global

    //NexTouchEventCb cb_push;
    //void *cbpush_ptr;
    //NexTouchEventCb cb_pop;
    //void *cbpop_ptr;
} NexObject;

void Nex_createObject(NexObject *object, uint8_t page_id, uint8_t component_id, char *name);

#ifdef __cplusplus
}
#endif

#endif /*NEXOBJECT_H*/