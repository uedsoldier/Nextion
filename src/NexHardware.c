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
    NexHardware_sendCommand("bkcmd=3"); // Always wait for return codes
    return NexHardware_waitResponse();
    
}

NexReturnCode NexHardware_waitResponse(void){
    #if defined(NEXTION_USE_CRC) && (NEXTION_USE_CRC > 0)
    #define NEX_RESPONSE_BYTES 4
    #else
    #define NEX_RESPONSE_BYTES 3
    #endif
    #if defined(NEXHARDWARE_LOG) && (NEXHARDWARE_LOG > 0)
    printf("NexHardware_waitResponse(). Waiting...\n");
    #endif
    NexReturnCode retCode;
    bool response = false;
    uint8_t byteRead, response_cnt = 0, index = 0;
    while(!response){
        while(NexSerial_dataAvailable() == 0);
        NexSerial_readByteBuffer(&byteRead);
        Nex_rxBuffer[index++] = byteRead;
        #if defined(NEXTION_USE_CRC) && (NEXTION_USE_CRC > 0)
        if(byteRead == NEXTION_END_BYTE_CRC || byteRead == NEXTION_PREAMBLE_BYTE_CRC)
            response_cnt++;
        #else
        if(byteRead == NEXTION_END_BYTE)
            response_cnt++;
        #endif
        if(response_cnt == NEX_RESPONSE_BYTES)
            response = true;
    }
    retCode = Nex_rxBuffer[0];
    return retCode;
    
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

//NexReturnCode NexHardware_setAutoWakeOnTouch(bool autowake){
//
//}
//
//NexReturnCode NexHardware_sleepOnNoTouch(uint16_t sleep_interval){
//
//}

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
