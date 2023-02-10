/**
 * @file NexTouch.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NEXTOUCH_H
#define NEXTOUCH_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>

typedef void (*NexTouchEventCb)(void *ptr);

typedef struct _NexObject
{
    uint8_t page_id;      /* Page ID */
    uint8_t component_id;      /* Component ID */
    char name[16]; /* An unique name */
    NexTouchEventCb cb_push;
    void *cbpush_ptr;
    NexTouchEventCb cb_pop;
    void *cbpop_ptr;
} NexObject;

#ifdef __cplusplus
}
#endif

#endif /*NEXTOUCH_H*/