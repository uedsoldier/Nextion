/**
 * @file NexPage.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "NexPage.h"


void NexPage_init(NexPage *nex_page,uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, Nex_pageBackgroundFill background_fill){
    NexObject_init(&nex_page->widget.object, component_id, page_id, name );
    #if defined(NEX_PAGE_USE_EFFECTS) && (NEX_PAGE_USE_EFFECTS > 0)
    nex_page->widget.effect = effect;
    #else
    nex_page->widget.effect = NEX_EFFECT_LOAD;
    #endif
    nex_page->background_fill = background_fill;
}


NexReturnCode NexPage_show(NexPage *nex_page){
    const char *objname = nex_page->widget.object.objname;
    if(objname == NULL){    // Object not yet initialized
        return NEX_RETCODE_NO_RETCODE;
    }
    memset(Nex_txBuffer, 0, sizeof(Nex_txBuffer));
    sprintf(Nex_txBuffer,"page %s",nex_page->widget.object.objname);
    NexHardware_sendCommand(Nex_txBuffer);
    //TODO
    return NEX_RETCODE_NO_RETCODE; //TODO
}


NexReturnCode NexPage_setBackGroundSolidColor(NexPage *nex_page, uint16_t bg_color ){
    if(nex_page->background_fill != NEXPAGE_BACKGROUND_FILL_SOLID_COLOR){
        return NEX_RETCODE_NO_RETCODE;
    }
    memset(Nex_txBuffer, 0, sizeof(Nex_txBuffer));
    sprintf(Nex_txBuffer,"%s.bco=%u",nex_page->widget.object.objname,bg_color);
    NexHardware_sendCommand(Nex_txBuffer);
    //TODO
    return NEX_RETCODE_NO_RETCODE; //TODO
}


NexReturnCode NexPage_setBackGroundImage(NexPage *nex_page, uint8_t pic_id){
    if(nex_page->background_fill != NEXPAGE_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    memset(Nex_txBuffer, 0, sizeof(Nex_txBuffer));
    sprintf(Nex_txBuffer,"%s.pic=%u",nex_page->widget.object.objname,pic_id);
    NexHardware_sendCommand(Nex_txBuffer);
    //TODO
    return NEX_RETCODE_NO_RETCODE; //TODO  
}

#if defined(NEX_PAGE_USE_EFFECTS) && (NEX_PAGE_USE_EFFECTS > 0)
NexReturnCode NexPage_setScrollPage(NexPage *nex_page, Nex_scrollDirection direction, uint8_t page_id){
    memset(Nex_txBuffer, 0, sizeof(Nex_txBuffer);
    switch(direction){
        case NEX_SCROLL_UP: sprintf(Nex_auxBuffer,"up"); break;
        case NEX_SCROLL_DOWN: sprintf(Nex_auxBuffer,"down"); break;
        case NEX_SCROLL_LEFT: sprintf(Nex_auxBuffer,"left"); break;
        case NEX_SCROLL_RIGHT: sprintf(Nex_auxBuffer,"right"); break;
    }
    sprintf(Nex_txBuffer,"%s.%s=%u",nex_page->widget.object.objname,Nex_auxBuffer,page_id);
    NexHardware_sendCommand(Nex_txBuffer);
    //TODO
    return NEX_RETCODE_NO_RETCODE; //TODO  
}
#endif
