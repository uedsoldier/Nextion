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

/**
 * @brief 
 * 
 * @param nex_widget 
 * @param component_id 
 * @param page_id 
 * @param name 
 * @return NexReturnCode 
 */
NexReturnCode NexWidget_init(NexWidget *nex_widget, uint8_t component_id, uint8_t page_id, const char *name){
    nex_widget.object.id = component_id;
    nex_widget.object.page_id = page_id;
    strcpy(nex_widget.object.objname,name);
}







