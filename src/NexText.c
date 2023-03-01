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

void NexText_init(NexText *nex_text, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, NexWidget_backgroundFill fill)
{
    NexObject_init(&nex_text->widget.object, page_id, component_id, name);
    nex_text->widget.object.type = NEXOBJECT_TYPE_TEXT;
    nex_text->widget.effect = effect;
    nex_text->backgroundFill = fill;
}

NexReturnCode NexText_setText(NexText *nex_text, const char *text)
{
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer, "%s.txt=\"%s\"", nex_text->widget.object.objname, text);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEXTEXT_LOG) && (NEXTEXT_LOG > 0)
    printf("setText() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

uint16_t NexText_getText(NexText *nex_text, char *text, uint16_t len)
{
    sprintf(Nex_cmdBuffer, "get %s.txt", nex_text->widget.object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    return 0; // TODO
}

NexReturnCode NexText_setFontColor(NexText *nex_text, uint16_t font_color)
{
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer, "%s.pco=%u", nex_text->widget.object.objname, font_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEXTEXT_LOG) && (NEXTEXT_LOG > 0)
    printf("setFontColor() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexText_setBackGroundColor(NexText *nex_text, uint16_t bg_color ){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer, "%s.bco=%u", nex_text->widget.object.objname, bg_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEXTEXT_LOG) && (NEXTEXT_LOG > 0)
    printf("setBackGroundColor() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexText_setBackGroundImage(NexText *nex_text, uint8_t pic_id){
    //NexReturnCode nex_retCode;
    if( nex_text->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.pic=%u",nex_text->widget.object.objname,pic_id);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setBackGroundImage() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexText_setCropImage(NexText *nex_text, uint8_t crop_image){
    //NexReturnCode nex_retCode;
    if( nex_text->backgroundFill != NEXWIDGET_BACKGROUND_FILL_CROP_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.picc=%u",nex_text->widget.object.objname,crop_image);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setCropImage() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

#if defined(NEXTEXT_USE_ADVANCED_FUNCTIONS) && (NEXTEXT_USE_ADVANCED_FUNCTIONS > 0)

NexReturnCode NexText_horizontalJustify(NexText *nex_text, NexWidget_horizontalAlign xcen){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer,"%s.xcen=%u",nex_text->widget.object.objname,xcen);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("horizontalJustify() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexText_verticalJustify(NexText *nex_text, NexWidget_verticalAlign ycen){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer,"%s.ycen=%u",nex_text->widget.object.objname,ycen);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("verticalJustify() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexText_setWordWrap(NexText *nex_text, bool word_wrap){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer,"%s.isbr=%u",nex_text->widget.object.objname,word_wrap);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setWordWrap() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}


#endif