/**
 * @file NexWidget.c
 * @author José Roberto Parra Trewartha (uedsoldier1990@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "NexWidget.h"

void NexWidget_init(NexWidget *nex_widget, uint8_t component_id, uint8_t page_id, const char *name){
    NexObject_init(&nex_widget->object,page_id,component_id,name);
    // TODO
}







