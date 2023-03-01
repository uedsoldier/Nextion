/**
 * @file NexScrollingText.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "NexScrollingText.h"

void NexScrollingText_init(NexScrollingText *nex_scrollingText, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, NexWidget_backgroundFill fill)
{
    NexObject_init(&nex_scrollingText->widget.object, page_id, component_id, name);
    nex_scrollingText->widget.object.type = NEXOBJECT_TYPE_SCROLLING_TEXT;
    nex_scrollingText->widget.effect = effect;
    nex_scrollingText->backgroundFill = fill;
}

NexReturnCode NexScrollingText_setText(NexScrollingText *nex_scrollingtext, const char *text)
{
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer, "%s.txt=\"%s\"", nex_scrollingtext->widget.object.objname, text);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEXTEXT_LOG) && (NEXTEXT_LOG > 0)
    printf("setText() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

uint16_t NexScrollingText_getText(NexScrollingText *nex_scrollingtext, char *text, uint16_t len)
{
    sprintf(Nex_cmdBuffer, "get %s.txt", nex_scrollingtext->widget.object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    return 0; // TODO
}

NexReturnCode NexScrollingText_setFontColor(NexScrollingText *nex_scrollingtext, uint16_t font_color)
{
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer, "%s.pco=%u", nex_scrollingtext->widget.object.objname, font_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEXTEXT_LOG) && (NEXTEXT_LOG > 0)
    printf("setFontColor() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexScrollingText_setBackGroundColor(NexScrollingText *nex_scrollingtext, uint16_t bg_color ){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer, "%s.bco=%u", nex_scrollingtext->widget.object.objname, bg_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEXTEXT_LOG) && (NEXTEXT_LOG > 0)
    printf("setBackGroundColor() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexScrollingText_setBackGroundImage(NexScrollingText *nex_scrollingtext, uint8_t pic_id){
    //NexReturnCode nex_retCode;
    if( nex_scrollingtext->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.pic=%u",nex_scrollingtext->widget.object.objname,pic_id);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setBackGroundImage() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexScrollingText_setCropImage(NexScrollingText *nex_scrollingtext, uint8_t crop_image){
    //NexReturnCode nex_retCode;
    if( nex_scrollingtext->backgroundFill != NEXWIDGET_BACKGROUND_FILL_CROP_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.picc=%u",nex_scrollingtext->widget.object.objname,crop_image);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setCropImage() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

#if defined(NEXSCROLLINGTEXT_USE_ADVANCED_FUNCTIONS) && (NEXSCROLLINGTEXT_USE_ADVANCED_FUNCTIONS > 0)

NexReturnCode NexScrollingText_horizontalJustify(NexScrollingText *nex_scrollingtext, NexWidget_horizontalAlign xcen){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer,"%s.xcen=%u",nex_scrollingtext->widget.object.objname,xcen);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("horizontalJustify() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexScrollingText_verticalJustify(NexScrollingText *nex_scrollingtext, NexWidget_verticalAlign ycen){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer,"%s.ycen=%u",nex_scrollingtext->widget.object.objname,ycen);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("verticalJustify() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexScrollingText_setWordWrap(NexScrollingText *nex_scrollingtext, bool word_wrap){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer,"%s.isbr=%u",nex_scrollingtext->widget.object.objname,word_wrap);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setWordWrap() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexScrollingText_setTextDirection(NexScrollingText *nex_scrollingText, NexScrollingText_direction direction){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer,"%s.dir=%u",nex_scrollingText->widget.object.objname,direction);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setTextDirection() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexScrollingText_setScrollingDistance(NexScrollingText *nex_scrollingText, uint8_t scrolling_distance){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer,"%s.dis=%u",nex_scrollingText->widget.object.objname,scrolling_distance);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setScrollingDistance() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexScrollingText_setIntervalTime(NexScrollingText *nex_scrollingText, uint16_t interval_time){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer,"%s.tim=%u",nex_scrollingText->widget.object.objname,interval_time);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("setIntervalTime() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexScrollingText_enableScrolling(NexScrollingText *nex_scrollingText, bool enable){
    //NexReturnCode nex_retCode;
    sprintf(Nex_cmdBuffer,"%s.en=%u",nex_scrollingText->widget.object.objname,enable);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXTEXT_LOG) && (NEXTEXT_LOG>0)
    printf("enableScrolling() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

#endif