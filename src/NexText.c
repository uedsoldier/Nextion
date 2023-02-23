/**
 * @file NexText.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "NexText.h"

void NexText_init(NexText *nex_text,uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect ){
    NexObject_init(&nex_text->widget.object, page_id, component_id, name);
}

NexReturnCode NexText_setText(NexText *nex_text, const char *text){
    memset(Nex_txBuffer, 0, sizeof(Nex_txBuffer));
    sprintf(Nex_txBuffer,"%s.txt=\"%s\"",nex_text->widget.object.objname,text);
    NexHardware_sendCommand(Nex_txBuffer);
    return NEX_RETCODE_ERROR; //TODO
}

uint16_t NexText_getText(NexText *nex_text, char *text, uint16_t len){
    memset(Nex_txBuffer, 0, sizeof(Nex_txBuffer));
    sprintf(Nex_txBuffer,"get %s.txt",nex_text->widget.object.objname);
    NexHardware_sendCommand(Nex_txBuffer);
    return 0; //TODO
}

