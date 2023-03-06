/**
 * @file NexSlider.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "NexSlider.h"

void NexSlider_init(NexSlider *nex_slider, uint8_t component_id, uint8_t page_id, const char *name, Nex_effect effect, NexWidget_backgroundFill fill){
    NexObject_init(&nex_slider->object,NEXOBJECT_TYPE_SLIDER,page_id, component_id, name);
    nex_slider->widget.effect = effect;
    nex_slider->backgroundFill = fill;
}

NexReturnCode NexSlider_setValue(NexSlider *nex_slider, uint8_t value){
    sprintf(Nex_cmdBuffer, "%s.val=%u", nex_slider->object.objname, value);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_SLIDER_LOG) && (NEX_SLIDER_LOG > 0)
    printf("setValue() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexSlider_getValue(NexSlider *nex_slider, uint8_t *value){
    sprintf(Nex_cmdBuffer, "get %s.val", nex_slider->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber(value);
    return nex_retCode;
}

NexReturnCode NexSlider_setBackGroundColor(NexSlider *nex_slider, uint16_t background_color){
    sprintf(Nex_cmdBuffer, "%s.bco=%u", nex_slider->object.objname, background_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_SLIDER_LOG) && (NEX_SLIDER_LOG > 0)
    printf("setBackGroundColor() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexSlider_setForeGroundColor(NexSlider *nex_slider, uint16_t foreground_color){
    sprintf(Nex_cmdBuffer, "%s.pco=%u", nex_slider->object.objname, foreground_color);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_SLIDER_LOG) && (NEX_SLIDER_LOG > 0)
    printf("setForegroundColor() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexSlider_getBackGroundColor(NexSlider *nex_slider, uint16_t *background_color){
    sprintf(Nex_cmdBuffer, "get %s.bco", nex_slider->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)background_color);
    return nex_retCode;
}

NexReturnCode NexSlider_getForeGroundColor(NexSlider *nex_slider, uint16_t *foreground_color){
    sprintf(Nex_cmdBuffer, "get %s.pco", nex_slider->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)foreground_color);
    return nex_retCode;
}

NexReturnCode NexSlider_setBackGroundImage(NexSlider *nex_slider, uint8_t pic_id){
    if( nex_slider->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.pic=%u",nex_slider->object.objname,pic_id);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEX_SLIDER_LOG) && (NEX_SLIDER_LOG>0)
    printf("setBackGroundImage() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexSlider_setForeGroundImage(NexSlider *nex_slider, uint8_t pic_id){
    if( nex_slider->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer,"%s.pic1=%u",nex_slider->object.objname,pic_id);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEX_SLIDER_LOG) && (NEX_SLIDER_LOG>0)
    printf("setForeGroundImage() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexSlider_getBackGroundImage(NexSlider *nex_slider, uint8_t *pic_id){
    if( nex_slider->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer, "get %s.pic", nex_slider->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)pic_id);
    return nex_retCode;
}

NexReturnCode NexSlider_getForeGroundImage(NexSlider *nex_slider, uint8_t *pic_id){
    if( nex_slider->backgroundFill != NEXWIDGET_BACKGROUND_FILL_IMAGE){
        return NEX_RETCODE_ERROR;
    }
    sprintf(Nex_cmdBuffer, "get %s.pic1", nex_slider->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)pic_id);
    return nex_retCode;
}

NexReturnCode NexSlider_setCornerRadius(NexSlider *nex_slider, uint8_t corner_radius){
    sprintf(Nex_cmdBuffer, "%s.dis=%u", nex_slider->object.objname, corner_radius);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_SLIDER_LOG) && (NEX_SLIDER_LOG > 0)
    printf("setCornerRadius() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexSlider_getCornerRadius(NexSlider *nex_slider, uint8_t *corner_radius){
    sprintf(Nex_cmdBuffer, "get %s.dis", nex_slider->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)corner_radius);
    return nex_retCode;
}

NexReturnCode NexSlider_setCursorHeight(NexSlider *nex_slider, uint8_t cursor_height){
    sprintf(Nex_cmdBuffer, "%s.hig=%u", nex_slider->object.objname, cursor_height);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_SLIDER_LOG) && (NEX_SLIDER_LOG > 0)
    printf("setCornerRadius() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexSlider_getCursorHeight(NexSlider *nex_slider, uint8_t *cursor_height){
    sprintf(Nex_cmdBuffer, "get %s.hig", nex_slider->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)cursor_height);
    return nex_retCode;
}

NexReturnCode NexSlider_setBackgroundWidthPercentage(NexSlider *nex_slider, uint8_t background_width_percentage){
    sprintf(Nex_cmdBuffer, "%s.ch=%u", nex_slider->object.objname, background_width_percentage);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_SLIDER_LOG) && (NEX_SLIDER_LOG > 0)
    printf("setCornerRadius() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexSlider_getBackgroundWidthPercentage(NexSlider *nex_slider, uint8_t *background_width_percentage){
    sprintf(Nex_cmdBuffer, "get %s.ch", nex_slider->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)background_width_percentage);
    return nex_retCode;
}

NexReturnCode NexSlider_setMinValue(NexSlider *nex_slider, uint16_t min_value){
    sprintf(Nex_cmdBuffer, "%s.minval=%u", nex_slider->object.objname, min_value);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_SLIDER_LOG) && (NEX_SLIDER_LOG > 0)
    printf("setCornerRadius() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexSlider_getMinValue(NexSlider *nex_slider, uint16_t *min_value){
    sprintf(Nex_cmdBuffer, "get %s.minval", nex_slider->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)min_value);
    return nex_retCode;
}

NexReturnCode NexSlider_setMaxValue(NexSlider *nex_slider, uint16_t max_value){
    sprintf(Nex_cmdBuffer, "%s.maxval=%u", nex_slider->object.objname, max_value);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
#if defined(NEX_SLIDER_LOG) && (NEX_SLIDER_LOG > 0)
    printf("setCornerRadius() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
#endif
    return nex_retCode;
}

NexReturnCode NexSlider_getMaxValue(NexSlider *nex_slider, uint16_t *max_value){
    sprintf(Nex_cmdBuffer, "get %s.maxval", nex_slider->object.objname);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    NexHardware_getNumber((uint32_t*)max_value);
    return nex_retCode;
}