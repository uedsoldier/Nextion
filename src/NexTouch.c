/**
 * @file NexTouch.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "NexTouch.h"

void NexTouch_attachPush( NexObject *nex_object, NexTouch_eventCallback push_callback, void *ptr){
    nex_object->cb_push = push_callback;
    nex_object->cbpush_ptr = ptr;
}

void NexTouch_detachPush( NexObject *nex_object){
    nex_object->cb_push = NULL;
    nex_object->cbpush_ptr = NULL;
}

void NexTouch_attachPop( NexObject *nex_object, NexTouch_eventCallback pop_callback, void *ptr){
    nex_object->cb_pop = pop_callback;
    nex_object->cbpop_ptr= ptr;
}

void NexTouch_detachPop( NexObject *nex_object){
    nex_object->cb_pop = NULL;
    nex_object->cbpop_ptr= NULL;
}

void NexTouch_push( NexObject *nex_object){
    if(nex_object->cb_push)
        nex_object->cb_push(nex_object->cbpush_ptr);
}

void NexTouch_pop( NexObject *nex_object){
    if(nex_object->cb_pop)
        nex_object->cb_pop(nex_object->cbpop_ptr);
}

void NexTouch_iterate( NexObject **list, uint8_t pid, uint8_t cid, bool event){
    NexObject *e = NULL;
    if(list == NULL)
    return;
    for(size_t i=0; (e = list[i]) != 0 ;i++){
        if(e->id == cid && e->page_id == pid){
            if(event == NEX_EVENT_PUSH){
                NexTouch_push(e);
            } else if(event == NEX_EVENT_POP) {
                NexTouch_pop(e);
            }
        }
    }

}