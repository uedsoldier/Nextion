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

/**
 * @brief 
 * 
 * @param command 
 * @return NexReturnCode 
 */
NexReturnCode Nex_sendCommand(char *command){
    // TODO
    return NEX_RETCODE_INSTRUCTION_SUCCESFUL;
}

/**
 * @brief 
 * 
 */
inline void NexHardware_clear_txBuffer(){
    memset(Nex_txBuffer,0,sizeof(Nex_txBuffer));
}
