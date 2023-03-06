/**
 * @file NexHardware.c
 * @author José Roberto Parra Trewartha (uedsoldier1990@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "NexHardware.h"

void NexHardware_sendCommand(const char *command)
{
    NEX_CLEAR_TX_BUFFER;
    NEX_CLEAR_RX_BUFFER;
    size_t command_length = strlen(command);
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("NexHardware_sendCommand(): <<%s>>\nCommand length:%u\n",command,command_length);
    #endif
    strcpy(Nex_txBuffer,command);
#if defined(NEXTION_USE_CRC) && (NEXTION_USE_CRC == 1)
    uint16_t crc16_modbus = CRC16(Nex_txBuffer,command_length,CRC16_MODBUS);
    Nex_txBuffer[command_length++] = (uint8_t)(crc16_modbus & 0x00FF);
    Nex_txBuffer[command_length++] = (uint8_t)((crc16_modbus >> 8) & 0x00FF);
    Nex_txBuffer[command_length++] = NEXTION_PREAMBLE_BYTE_CRC;
    Nex_txBuffer[command_length++] = NEXTION_END_BYTE_CRC;
    Nex_txBuffer[command_length++] = NEXTION_END_BYTE_CRC;
    Nex_txBuffer[command_length++] = NEXTION_END_BYTE_CRC;
#else
    Nex_txBuffer[command_length++] = NEXTION_END_BYTE;
    Nex_txBuffer[command_length++] = NEXTION_END_BYTE;
    Nex_txBuffer[command_length++] = NEXTION_END_BYTE;
#endif
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 1)
    for (size_t i = 0; i != command_length; i++)
    {
        printf(" -> txBuffer[%u]=0x%02X\n",i,Nex_txBuffer[i]);
    }
    
    #endif
    NexSerial_writeBuffer((uint8_t *)Nex_txBuffer, command_length);
}

NexReturnCode NexHardware_init(void){
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("NexHardware_init()\n");
    #endif
    NEX_CLEAR_TX_BUFFER;
    NEX_CLEAR_RX_BUFFER;
    NEX_CLEAR_CMD_BUFFER;
    NexHardware_sendCommand("");
    //NexHardware_waitResponse();
    NexHardware_sendCommand("bkcmd=3"); // Always wait for return codes
    return NexHardware_waitResponse();
    
}

NexReturnCode NexHardware_waitResponse(void){
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("NexHardware_waitResponse(). Waiting...\n");
    #endif
    NexReturnCode retCode;
    bool response = false;
    uint8_t byteRead, response_cnt = 0, index = 0, previous_byte = NEXTION_END_BYTE;
    while(!response){
        while(NexSerial_dataAvailable() == 0);
        NexSerial_readByteBuffer(&byteRead);
        Nex_rxBuffer[index++] = byteRead;
        #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 1)
        printf("Byte read: 0x%02X\n",byteRead);
        #endif
        if(byteRead == NEXTION_END_BYTE && previous_byte == NEXTION_END_BYTE){
            response_cnt++;
        }
            
        if(response_cnt == NEX_RESPONSE_BYTES-1){
            response = true;
        }
        previous_byte = byteRead;  
    }
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 1)
    printf("NexHardware_waitResponse(). Bytes read:%u\n",index);
    #endif
    retCode = Nex_rxBuffer[0];
    return retCode;
}

bool NexHardware_getString(char *buffer,size_t *len){
    bool retVal = false;
    uint8_t *p=Nex_rxBuffer;
    uint8_t retCode = *p++;
    uint8_t readByte = *p++;
    if(retCode == NEX_RETCODE_STRING_DATA_ENCLOSED)
    {
        retVal = true;
        while(readByte != NEXTION_END_BYTE)
        {
            *buffer++ = readByte;
            (*len)++;
            readByte = *p++;
        };
    }
    return retVal;
}

bool NexHardware_getNumber(uint32_t *number){
    bool retVal = false;
    uint8_t *p=Nex_rxBuffer;
    uint8_t *nP = (uint8_t *)number;
    uint8_t retCode = *p++;
    uint8_t readByte = *p++;
    if(retCode == NEX_RETCODE_NUMERIC_DATA_ENCLOSED)
    {
        retVal = true;
        while(readByte != NEXTION_END_BYTE)
        {
            *nP++ = readByte;
            readByte = *p++;
        };
    }
    return retVal;
}

void NexHardware_reset(){
    NexHardware_sendCommand("rest");
}

static bool NexHardware_validateEndSequence(void){
#if defined(NEXTION_USE_CRC) && (NEXTION_USE_CRC > 0)
    // TODO return Nex_rxBuffer[1] == NEXTION_PREAMBLE_BYTE_CRC && Nex_rxBuffer[2] == NEXTION_END_BYTE_CRC && Nex_rxBuffer[3] == NEXTION_END_BYTE_CRC && Nex_rxBuffer[4] == NEXTION_END_BYTE_CRC ;
#else
    return Nex_rxBuffer[1] == NEXTION_END_BYTE && Nex_rxBuffer[2] == NEXTION_END_BYTE && Nex_rxBuffer[3] == NEXTION_END_BYTE; 
#endif
}

NexReturnCode NexHardware_sleep(bool sleep){
    NexSerial_flushBuffer();
    sprintf(Nex_cmdBuffer,"sleep=%u",sleep);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("sleep() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
    #endif
    return nex_retCode;

}

NexReturnCode NexHardware_setAutoWakeOnTouch(bool autowake){
    NexSerial_flushBuffer();
    sprintf(Nex_cmdBuffer,"thup=%u",autowake);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("setAutoWakeOnTouch() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexHardware_sleepOnNoTouch(uint16_t sleep_interval){
    NexSerial_flushBuffer();
    sprintf(Nex_cmdBuffer,"thsp=%u",sleep_interval);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("sleepOnNoTouch() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexHardware_setBacklightLevel(uint8_t backlight_level){
    NexSerial_flushBuffer();
    sprintf(Nex_cmdBuffer,"dim=%u",backlight_level);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("setBacklightLevel() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexHardware_setBacklightLevelSave(uint8_t backlight_level){
    NexSerial_flushBuffer();
    sprintf(Nex_cmdBuffer,"dims=%u",backlight_level);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("setBacklightLevelSave() %s\n", nex_retCode == NEX_RETCODE_INSTRUCTION_SUCCESFUL ? "OK" : "NOT OK");
    #endif
    return nex_retCode;
}

//NexReturnCode NexHardware_setBaudRate(uint32_t baud_rate){
//
//}
//
//NexReturnCode NexHardware_setBaudRateSave(uint32_t baud_rate){
//
//}

NexReturnCode NexHardware_event(NexObject **nex_listenList){
    uint8_t page_id, component_id;
    bool event;
    NexHardware_waitResponse();
    switch (Nex_rxBuffer[0])
    {
        // Touch event for components
    case NEX_RETCODE_TOUCH_EVENT:
        
        NexHardware_touchEvent(&page_id, &component_id, &event);
        NexTouch_iterate(nex_listenList,page_id,component_id,NexTouch_press);
        break;
    case NEX_RETCODE_TOUCH_COORDINATE_SLEEP:
        NexHardware_sleepEvent(&event);
        break;
    case NEX_RETCODE_AUTO_WAKE_FROM_SLEEP:
        // touch and untouch events arrived earlier
        NexHardware_autoWakeEvent(&event);
        break;
    case NEX_RETCODE_AUTO_ENTERED_SLEEP_MODE:
        NexHardware_autoEnteredSleep();
        break;
    default:
        break;
    }
    
}

void NexHardware_touchEvent(uint8_t *page_id, uint8_t *component_id, bool *event){
    *page_id = Nex_rxBuffer[1];
    *component_id = Nex_rxBuffer[2];
    *event = Nex_rxBuffer[3];
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("touch event: %s Component: %u Page: %u\n", *event? "press":"release" , component_id, page_id );
    #endif
}

void NexHardware_sleepEvent(bool *event){
    NexTouch_x_coord= make16(Nex_rxBuffer[1],Nex_rxBuffer[2]);
    NexTouch_y_coord = make16(Nex_rxBuffer[3],Nex_rxBuffer[4]);   
    *event = Nex_rxBuffer[5];
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("Sleep touch event: %s x=%u y=%u\n", *event? "press":"release" , NexTouch_x_coord, NexTouch_y_coord );
    #endif
}

void NexHardware_autoWakeEvent( bool *event){
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("Autowake on touch event. Callback is %snull.\n", NexHardware_autoWakeCallback == NULL? "":"not ");   
    #endif
    if(NexHardware_autoWakeCallback){
        NexHardware_autoWakeCallback(NexHardware_autoWakeCallbackPtr);
    }
    
}

void NexHardware_autoEnteredSleep(){
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("Auto entered sleep mode. Callback is %snull.\n", NexHardware_autoSleepCallback == NULL? "":"not ");
    #endif
    if(NexHardware_autoSleepCallback){
        NexHardware_autoSleepCallback(NexHardware_autoSleepCallbackPtr);
    }
}

void NexHardware_attachAutoWakeEvent(NexHardware_eventCallback eventCallback, void *ptr){
    NexHardware_autoWakeCallback = eventCallback;
    NexHardware_autoWakeCallbackPtr = ptr;
}

void NexHardwawe_detachAutoWakeEvent(){
    NexHardware_autoWakeCallback = NULL;
}

void NexHardware_attachAutoSleepEvent(NexHardware_eventCallback eventCallback, void *ptr){
    NexHardware_autoSleepCallback = eventCallback;
    NexHardware_autoSleepCallbackPtr = ptr;
}

void NexHardwawe_detachAutoSleepEvent(){
    NexHardware_autoSleepCallback = NULL;
}