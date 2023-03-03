/**
 * @file NexNumber.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "NexNumber.h"

void NexNumber_init(NexNumber *nex_number, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, NexWidget_backgroundFill fill){
    NexObject_init(&nex_number->widget.object, page_id, component_id, name);
    nex_number->widget.object.type = NEXOBJECT_TYPE_TEXT;
    nex_number->widget.effect = effect;
    nex_number->backgroundFill = fill;
}

NexReturnCode NexNumber_setValue(NexNumber *nex_number, uint32_t value){
    sprintf(Nex_cmdBuffer, "%s.val=%lu", nex_number->widget.object.objname, value);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEXTEXT_LOG) && (NEXTEXT_LOG > 0)
    printf("setValue() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexNumber_getValue(NexNumber *nex_number, uint32_t *value){
    sprintf(Nex_cmdBuffer, "get %s.val", nex_number->widget.object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber(value);
    return nex_retCode;
}

NexReturnCode NexNumber_setLength(NexNumber *nex_number, uint8_t length){

}

#if defined(NEXNUMBER_USE_ADVANCED_FUNCTIONS) && (NEXNUMBER_USE_ADVANCED_FUNCTIONS > 0)

NexReturnCode NexNumber_horizontalJustify(NexNumber *nex_number, NexWidget_horizontalAlign xcen){
    sprintf(Nex_cmdBuffer,"%s.xcen=%u",nex_number->widget.object.objname,xcen);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("horizontalJustify() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexNumber_verticalJustify(NexNumber *nex_number, NexWidget_verticalAlign ycen){
    sprintf(Nex_cmdBuffer,"%s.ycen=%u",nex_number->widget.object.objname,ycen);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("verticalJustify() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexNumber_setWordWrap(NexNumber *nex_number, bool word_wrap){
    sprintf(Nex_cmdBuffer,"%s.isbr=%u",nex_number->widget.object.objname,word_wrap);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setWordWrap() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

#endif

NexReturnCode NexNumber_setFontColor(NexNumber *nex_number, uint16_t font_color){
    sprintf(Nex_cmdBuffer, "%s.pco=%u", nex_number->widget.object.objname, font_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEXTEXT_LOG) && (NEXTEXT_LOG > 0)
    printf("setFontColor() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexNumber_setBackGroundColor(NexNumber *nex_number, uint16_t bg_color){
    sprintf(Nex_cmdBuffer, "%s.bco=%u", nex_number->widget.object.objname, bg_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEXTEXT_LOG) && (NEXTEXT_LOG > 0)
    printf("setBackGroundColor() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexNumber_setBackGroundImage(NexNumber *nex_number, uint8_t pic_id){
    if( nex_number->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.pic=%u",nex_number->widget.object.objname,pic_id);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setBackGroundImage() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexNumber_setCropImage(NexNumber *nex_number, uint8_t crop_image){
    if( nex_number->backgroundFill != NEXWIDGET_BACKGROUND_FILL_CROP_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.picc=%u",nex_number->widget.object.objname,crop_image);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setCropImage() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexNumber_setFormat(NexNumber *nex_number, NexNumber_format format){
    sprintf(Nex_cmdBuffer,"%s.format=%u",nex_number->widget.object.objname,format);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setWordWrap() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}