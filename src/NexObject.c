/**
 * @file NexObject.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "NexObject.h"

void NexObject_init(NexObject *object, uint8_t page_id, uint8_t component_id, const char *name){
    object->id = component_id;
    object->page_id = page_id;
    strcpy(object->objname,name);
}