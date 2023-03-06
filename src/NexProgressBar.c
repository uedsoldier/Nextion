/**
 * @file NexProgressBar.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "NexProgressBar.h"

void NexProgressBar_init(NexProgressBar *nex_progress_bar, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, NexWidget_backgroundFill fill){
    NexObject_init(&nex_progress_bar->object,NEXOBJECT_TYPE_PROGRESS_BAR,page_id, component_id, name);
    nex_progress_bar->widget.effect = effect;
    nex_progress_bar->backgroundFill = fill;
}

NexReturnCode NexProgressBar_setValue(NexProgressBar *nex_progress_bar, uint8_t value){
    sprintf(Nex_cmdBuffer, "%s.val=%u", nex_progress_bar->object.objname, value);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_PROGRESS_BAR_LOG) && (NEX_PROGRESS_BAR_LOG > 0)
    printf("setValue() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexProgressBar_getValue(NexProgressBar *nex_progress_bar, uint8_t *value){
    sprintf(Nex_cmdBuffer, "get %s.val", nex_progress_bar->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber(value);
    return nex_retCode;
}

NexReturnCode NexProgressBar_setBackGroundColor(NexProgressBar *nex_progress_bar, uint16_t background_color){
    sprintf(Nex_cmdBuffer, "%s.bco=%u", nex_progress_bar->object.objname, background_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_PROGRESS_BAR_LOG) && (NEX_PROGRESS_BAR_LOG > 0)
    printf("setBackGroundColor() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexProgressBar_setForeGroundColor(NexProgressBar *nex_progress_bar, uint16_t foreground_color){
    sprintf(Nex_cmdBuffer, "%s.pco=%u", nex_progress_bar->object.objname, foreground_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_PROGRESS_BAR_LOG) && (NEX_PROGRESS_BAR_LOG > 0)
    printf("setForegroundColor() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexProgressBar_getBackGroundColor(NexProgressBar *nex_progress_bar, uint16_t *background_color){
    sprintf(Nex_cmdBuffer, "get %s.bco", nex_progress_bar->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)background_color);
    return nex_retCode;
}

NexReturnCode NexProgressBar_getForeGroundColor(NexProgressBar *nex_progress_bar, uint16_t *foreground_color){
    sprintf(Nex_cmdBuffer, "get %s.pco", nex_progress_bar->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)foreground_color);
    return nex_retCode;
}

NexReturnCode NexProgressBar_setBackGroundImage(NexProgressBar *nex_progress_bar, uint8_t pic_id){
    if( nex_progress_bar->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.pic=%u",nex_progress_bar->object.objname,pic_id);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEX_PROGRESS_BAR_LOG) && (NEX_PROGRESS_BAR_LOG>0)
    printf("setBackGroundImage() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexProgressBar_setForeGroundImage(NexProgressBar *nex_progress_bar, uint8_t pic_id){
    if( nex_progress_bar->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.pic1=%u",nex_progress_bar->object.objname,pic_id);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEX_PROGRESS_BAR_LOG) && (NEX_PROGRESS_BAR_LOG>0)
    printf("setForeGroundImage() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexProgressBar_getBackGroundImage(NexProgressBar *nex_progress_bar, uint8_t *pic_id){
    if( nex_progress_bar->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer, "get %s.pic", nex_progress_bar->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)pic_id);
    return nex_retCode;
}

NexReturnCode NexProgressBar_getForeGroundImage(NexProgressBar *nex_progress_bar, uint8_t *pic_id){
    if( nex_progress_bar->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer, "get %s.pic1", nex_progress_bar->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)pic_id);
    return nex_retCode;
}

NexReturnCode NexProgressBar_setCornerRadius(NexProgressBar *nex_progress_bar, uint8_t corner_radius){
    sprintf(Nex_cmdBuffer, "%s.dis=%u", nex_progress_bar->object.objname, corner_radius);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_PROGRESS_BAR_LOG) && (NEX_PROGRESS_BAR_LOG > 0)
    printf("setCornerRadius() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexProgressBar_getCornerRadius(NexProgressBar *nex_progress_bar, uint8_t *corner_radius){
    sprintf(Nex_cmdBuffer, "get %s.dis", nex_progress_bar->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)corner_radius);
    return nex_retCode;
}