/**
 * @file NexGpio.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "NexGpio.h"

NexReturnCode NexGpio_config(uint8_t gpio_num, NexGpio_mode mode, const char *bound_component){
    if(bound_component == NULL)
        sprintf(Nex_cmdBuffer,"cfgpio %u,%u,0",gpio_num,mode);
    else
        sprintf(Nex_cmdBuffer,"cfgpio %u,%u,%s",gpio_num,mode,bound_component);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXGPIO_LOG) && (NEXGPIO_LOG>0)
    printf("gpio_config() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexGpio_setOutput(uint8_t gpio_num, bool state){
    sprintf(Nex_cmdBuffer,"pio%u=%u",gpio_num,state);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXGPIO_LOG) && (NEXGPIO_LOG>0)
    printf("gpio_setOutput() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexGpio_setPwmDuty(uint8_t gpio_num, uint8_t duty){
    sprintf(Nex_cmdBuffer,"pwm%u=%u",gpio_num,duty);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXGPIO_LOG) && (NEXGPIO_LOG>0)
    printf("gpio_setPwmDuty() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}

NexReturnCode NexGpio_setPwmFrequency(uint16_t freq){
    sprintf(Nex_cmdBuffer,"pwmf=%u",freq);
    NexHardware_sendCommand(Nex_cmdBuffer);
    nex_retCode = NexHardware_waitResponse();
    #if defined(NEXGPIO_LOG) && (NEXGPIO_LOG>0)
    printf("gpio_setPwmFrequency() %s\n",nex_retCode==NEX_RETCODE_INSTRUCTION_SUCCESFUL? "OK":"NOT OK");
    #endif
    return nex_retCode;
}
