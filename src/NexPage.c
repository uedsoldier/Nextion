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

/**
 * @brief 
 * 
 * @param nex_page 
 * @param component_id 
 * @param page_id 
 * @param name 
 * @param effect 
 */
void NexPage_init(NexPage *nex_page,uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect){
    NexWidget_init(nex_page->widget, component_id, page_id, name );
    #if defined(NEX_PAGE_USE_EFFECTS) && (NEX_PAGE_USE_EFFECTS > 0)
    nex_page->widget.effect = effect;
    #else
    nex_page->widget.effect = NEX_EFFECT_LOAD;
    #endif
}

/**
 * @brief 
 * 
 * @param nex_page 
 * @return NexReturnCode 
 */
NexReturnCode NexPage_show(NexPage *nex_page){
    const char *objname = nex_page->widget.object.objname;
    if(objname == NULL){
        return false;
    }
    NexHardware_clear_txBuffer();
    //TODO
}

/**
 * @brief 
 * 
 * @param nex_page 
 * @param bg_color 
 * @return NexReturnCode 
 */
NexReturnCode NexPage_setBackGroundSolidColor(NexPage *nex_page, uint16_t bg_color ){
    if(nex_page->background_fill != NEXPAGE_BACKGROUND_FILL_SOLID_COLOR){
        return NEX_RETCODE_ERROR;
    }
    NexHardware_clear_txBuffer();
    // TODO
}

/**
 * @brief 
 * 
 * @param nex_page 
 * @return NexReturnCode 
 */
NexReturnCode NexPage_setBackGroundImage(NexPage *nex_page){
    if(nex_page->background_fill != NEXPAGE_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    NexHardware_clear_txBuffer();
    // TODO    
}

#if defined(NEX_PAGE_USE_EFFECTS) && (NEX_PAGE_USE_EFFECTS > 0)
/**
 * @brief 
 * 
 * @param nex_page 
 * @param direction 
 * @param page_id 
 * @return NexReturnCode 
 */
NexReturnCode NexPage_setScrollPage(NexPage *nex_page, Nex_scrollDirection direction, uint8_t page_id){
    NexHardware_clear_txBuffer();
    //TODO
}
#endif
