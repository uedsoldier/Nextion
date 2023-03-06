/**
 * @file NexTouch.h
 * @author José Roberto Parra Trewartha (uedsoldier1990@gmail.com)
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
#include "NexObject.h"


#define NEX_EVENT_PUSH true
#define NEX_EVENT_POP false

uint16_t NexTouch_x_coord, NexTouch_y_coord; 
bool NexTouch_press;

/**
 * @brief 
 * 
 * @param nex_object 
 * @param push_callback 
 * @param ptr 
 */
void NexTouch_attachPush( NexObject *nex_object, NexTouch_eventCallback push_callback, void *ptr);

/**
 * @brief 
 * 
 * @param nex_object 
 */
void NexTouch_detachPush( NexObject *nex_object);

/**
 * @brief 
 * 
 * @param nex_object 
 * @param pop_callback 
 * @param ptr 
 */
void NexTouch_attachPop( NexObject *nex_object, NexTouch_eventCallback pop_callback, void *ptr);

/**
 * @brief 
 * 
 * @param nex_object 
 */
void NexTouch_detachPop( NexObject *nex_object);

/**
 * @brief 
 * 
 * @param nex_object 
 */
void NexTouch_push( NexObject *nex_object);

/**
 * @brief 
 * 
 * @param nex_object 
 */
void NexTouch_pop( NexObject *nex_object);

/**
 * @brief 
 * 
 * @param list 
 * @param pid 
 * @param cid 
 * @param event 
 */
void NexTouch_iterate( NexObject **list, uint8_t pid, uint8_t cid, bool event);

#ifdef __cplusplus
}
#endif

#endif /*NEXTOUCH_H*/