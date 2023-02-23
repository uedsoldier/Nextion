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
    size_t command_length = strlen(Nex_txBuffer);
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
    NexHardware_sendCommand("");
    NexHardware_sendCommand("bkcmd=3");

}
