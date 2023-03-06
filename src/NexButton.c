/**
 * @file NexButton.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "NexButton.h"

void NexButton_init(NexButton *nex_button, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, NexWidget_backgroundFill fill)
{
    NexObject_init(&nex_button->object,NEXOBJECT_TYPE_BUTTON,page_id, component_id, name);
    nex_button->widget.effect = effect; 
    nex_button->backgroundFill = fill;
}

NexReturnCode NexButton_setText(NexButton *nex_button, const char *text)
{
    NexReturnCode retCode;
    sprintf(Nex_cmdBuffer, "%s.txt=\"%s\"", nex_button->object.objname, text);
    NexHardware_sendCommand(Nex_cmdBuffer);
    retCode = NexHardware_waitResponse();
#if defined(NEXBUTTON_LOG) && (NEXBUTTON_LOG > 0)
    printf("setText() %s\n", retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return retCode;
}

uint16_t NexButton_getText(NexButton *nex_button, char *text, uint16_t len)
{
    sprintf(Nex_cmdBuffer, "get %s.txt", nex_button->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    return 0; // TODO
}

NexReturnCode NexButton_setFontColor(NexButton *nex_button, uint16_t font_color)
{
    NexReturnCode retCode;
    sprintf(Nex_cmdBuffer, "%s.pco=%u", nex_button->object.objname, font_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    retCode = NexHardware_waitResponse();
#if defined(NEXBUTTON_LOG) && (NEXBUTTON_LOG > 0)
    printf("setFontColor() %s\n", retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return retCode;
}

NexReturnCode NexButton_setPressFontColor(NexButton *nex_button, uint16_t press_font_color){
    NexReturnCode retCode;
    sprintf(Nex_cmdBuffer, "%s.pco2=%u", nex_button->object.objname, press_font_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    retCode = NexHardware_waitResponse();
#if defined(NEXBUTTON_LOG) && (NEXBUTTON_LOG > 0)
    printf("setPressFontColor() %s\n", retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return retCode;
}

NexReturnCode NexButton_setBackGroundColor(NexButton *nex_button, uint16_t bg_color ){
    NexReturnCode retCode;
    sprintf(Nex_cmdBuffer, "%s.bco=%u", nex_button->object.objname, bg_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    retCode = NexHardware_waitResponse();
#if defined(NEXBUTTON_LOG) && (NEXBUTTON_LOG > 0)
    printf("setBackGroundColor() %s\n", retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return retCode;
}

NexReturnCode NexButton_setPressBackGroundColor(NexButton *nex_button, uint16_t press_bg_color){
    NexReturnCode retCode;
    sprintf(Nex_cmdBuffer, "%s.bco2=%u", nex_button->object.objname, press_bg_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    retCode = NexHardware_waitResponse();
#if defined(NEXBUTTON_LOG) && (NEXBUTTON_LOG > 0)
    printf("setPressBackGroundColor() %s\n", retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return retCode;
}

NexReturnCode NexButton_setBackGroundImage(NexButton *nex_button, uint8_t pic_id){
    NexReturnCode retCode;
    if( nex_button->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.pic=%u",nex_button->object.objname,pic_id);
    NexHardware_sendCommand(Nex_cmdBuffer);
    retCode = NexHardware_waitResponse();
    #if defined(NEXBUTTON_LOG) && (NEXBUTTON_LOG>0)
    printf("setBackGroundImage() %s\n",retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return retCode;
}

NexReturnCode NexButton_setCropImage(NexButton *nex_button, uint8_t crop_image){
    NexReturnCode retCode;
    if( nex_button->backgroundFill != NEXWIDGET_BACKGROUND_FILL_CROP_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.picc=%u",nex_button->object.objname,crop_image);
    NexHardware_sendCommand(Nex_cmdBuffer);
    retCode = NexHardware_waitResponse();
    #if defined(NEXBUTTON_LOG) && (NEXBUTTON_LOG>0)
    printf("setCropImage() %s\n",retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return retCode;
}

#if defined(NexButton_USE_ADVANCED_FUNCTIONS) && (NexButton_USE_ADVANCED_FUNCTIONS > 0)

NexReturnCode NexButton_horizontalJustify(NexButton *nex_button, NexButton_horizontalAlign xcen){
    NexReturnCode retCode;
    sprintf(Nex_cmdBuffer,"%s.xcen=%u",nex_button->object.objname,xcen);
    NexHardware_sendCommand(Nex_cmdBuffer);
    retCode = NexHardware_waitResponse();
    #if defined(NEXBUTTON_LOG) && (NEXBUTTON_LOG>0)
    printf("horizontalJustify() %s\n",retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return retCode;
}

NexReturnCode NexButton_verticalJustify(NexButton *nex_button, NexButton_verticalAlign ycen){
    NexReturnCode retCode;
    sprintf(Nex_cmdBuffer,"%s.ycen=%u",nex_button->object.objname,ycen);
    NexHardware_sendCommand(Nex_cmdBuffer);
    retCode = NexHardware_waitResponse();
    #if defined(NEXBUTTON_LOG) && (NEXBUTTON_LOG>0)
    printf("verticalJustify() %s\n",retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return retCode;
}

NexReturnCode NexButton_setWordWrap(NexButton *nex_button, bool word_wrap){
    NexReturnCode retCode;
    sprintf(Nex_cmdBuffer,"%s.isbr=%u",nex_button->object.objname,word_wrap);
    NexHardware_sendCommand(Nex_cmdBuffer);
    retCode = NexHardware_waitResponse();
    #if defined(NEXBUTTON_LOG) && (NEXBUTTON_LOG>0)
    printf("setWordWrap() %s\n",retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return retCode;
}


#endif