/**
 * @file NexHardware.h
 * @author José Roberto Parra Trewartha (uedsoldier1990@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-02-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef NEXHARDWARE_H
#define NEXHARDWARE_H

#ifdef __cplusplus
extern "C"
{
#endif

#pragma region Dependencies
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "NexObject.h"
#include "NexTouch.h"
#include "crc.h"
#pragma endregion

/**
 * @brief 
 * 
 */
typedef void (*NexHardware_eventCallback)(void *ptr);

/**
 * @brief Log level for NexHardware functionalities
 */
#define NEXHARDWARE_LOG 1
/**
 * @brief
 *
 */
#define NEXTION_USE_CRC 1

/**
 * @brief End of sequence byte (with USE_CRC enabled)
 */
#define NEXTION_END_BYTE_CRC 0xFE
    
/**
 * @brief End of sequence preamble byte (with USE_CRC enabled)
 */ 
#define NEXTION_PREAMBLE_BYTE_CRC    0x01

/**
 * @brief End of sequence byte
 */
#define NEXTION_END_BYTE 0xFF

/**
 * @brief 
 * 
 */
#define NEX_CLEAR_TX_BUFFER   memset(Nex_txBuffer,0,sizeof(Nex_txBuffer)) \

/**
 * @brief 
 * 
 */
#define NEX_CLEAR_RX_BUFFER   memset(Nex_rxBuffer,0,sizeof(Nex_rxBuffer)) 
    
/**
 * @brief 
 * 
 */
#define NEX_CLEAR_CMD_BUFFER   memset(Nex_cmdBuffer,0,sizeof(Nex_cmdBuffer)) 

/**
 * @brief Response bytes quantity
 * 
 */
#define NEX_RESPONSE_BYTES 3

/**
 * @brief
 *
 */
typedef enum _NexReturnCode
{
    NEX_RETCODE_NEXTION_STARTUP = 0x00,                    // Returned when Nextion has started or reset. Since Nextion Editor v1.65.0, the Startup preamble is not at the firmware level but has been moved to a printh statement in Program.s allowing a user to keep, modify or remove as they choose.
    NEX_RETCODE_INVALID_INSTRUCTION = 0x00,                // Returned when instruction sent by user has failed
    NEX_RETCODE_INSTRUCTION_SUCCESFUL = 0x01,              // Returned when instruction sent by user was successful
    NEX_RETCODE_INVALID_COMPONENT_ID = 0x02,               // Returned when invalid Component ID or name was used
    NEX_RETCODE_INVALID_PAGE_ID = 0x03,                    // Returned when invalid Page ID or name was used
    NEX_RETCODE_INVALID_PICTURE_ID = 0x04,                 // Returned when invalid Picture ID was used
    NEX_RETCODE_INVALID_FONT_ID = 0x05,                    // Returned when invalid Font ID was used
    NEX_RETCODE_INVALID_FILE_OPERATION = 0x06,             // Returned when File operation fails
    NEX_RETCODE_INVALID_CRC = 0x09,                        // Returned when Instructions with CRC validation fails their CRC check
    NEX_RETCODE_INVALID_BAUDRATE = 0x11,                   // Returned when invalid Baud rate was used
    NEX_RETCODE_INVALID_WAVEFORM_ID_CHANNEL_NUMBER = 0x12, // Returned when invalid Waveform ID or Channel # was used
    NEX_RETCODE_INVALID_VARIABLE_NAME = 0x1A,              // Returned when invalid Variable name or invalid attribute was used
    NEX_RETCODE_INVALID_VARIABLE_OPERATION = 0x1B,         // Returned when Operation of Variable is invalid. ie: Text assignment t0.txt=abc or t0.txt=23, Numeric assignment j0.val=”50″ or j0.val=abc
    NEX_RETCODE_ASIGNMENT_FAILED = 0x1C,                   // Returned when attribute assignment failed to assign
    NEX_RETCODE_EEPROM_OPERATION_FAILED = 0x1D,            // Returned when an EEPROM Operation has failed
    NEX_RETCODE_INVALID_PARAMETERS_QUANTITY = 0x1E,        // Returned when the number of instruction parameters is invalid
    NEX_RETCODE_IO_OPERATION_FAILED = 0x1F,                // Returned when an IO operation has failed
    NEX_RETCODE_INVALID_ESCAPE_CHARACTER = 0x20,           // Returned when an unsupported escape character is used
    NEX_RETCODE_VARIABLE_NAME_TOO_LONG = 0x23,             // Returned when variable name is too long. Max length is 29 characters: 14 for page + “.” + 14 for component.
    NEX_RETCODE_SERIAL_BUFFER_OVERFLOW = 0x24,             // Returned when a Serial Buffer overflow occurs. Buffer will continue to receive the current instruction, all previous instructions are lost.
    NEX_RETCODE_TOUCH_EVENT = 0x65,                        // Returned when Touch occurs and component’s corresponding Send Component ID is checked in the users HMI design.
    NEX_RETCODE_CURRENT_PAGE_NUMBER = 0x66,                // Returned when the sendme command is used.
    NEX_RETCODE_TOUCH_COORDINATE_AWAKE = 0x67,             // Returned when sendxy=1 and not in sleep mode
    NEX_RETCODE_TOUCH_COORDINATE_SLEEP = 0x68,             // Returned when sendxy=1 and exiting sleep
    NEX_RETCODE_STRING_DATA_ENCLOSED = 0x70,               // Returned when using get command for a string. Each byte is converted to char.
    NEX_RETCODE_NUMERIC_DATA_ENCLOSED = 0x71,              // Returned when get command to return a number 4 byte 32-bit value in little endian order.
    NEX_RETCODE_AUTO_ENTERED_SLEEP_MODE = 0x86,            // Returned when Nextion enters sleep automatically. Using sleep=1 will not return an 0x86
    NEX_RETCODE_AUTO_WAKE_FROM_SLEEP = 0x87,               // Returned when Nextion leaves sleep automatically. Using sleep=0 will not return an 0x87
    NEX_RETCODE_START_MICROSD_UPGRADE = 0x89,              // Returned when power on detects inserted microSD
    NEX_RETCODE_TRANSPARENT_DATA_FINISHED = 0xFD,          // Returned when all requested bytes of Transparent Data mode have been received, and is now leaving transparent data mode (see https://nextion.tech/instruction-set/#s1_16 )
    NEX_RETCODE_TRANSPARENT_DATA_READY = 0xFE,             // 	0xFE 0xFF 0xFF 0xFF Returned when requesting Transparent Data mode, and device is now ready to begin receiving the specified quantity of data (see https://nextion.tech/instruction-set/#s1_16 )
    NEX_RETCODE_ERROR,
    NEX_RETCODE_NO_NEX_RETCODE                                  // No code was returned from device, because no command was issued
} NexReturnCode;


#pragma region Callback definitions
/**
 * @brief 
 * 
 */
void (*NexSerial_readByteBuffer)(uint8_t*);

/**
 * @brief 
 * 
 */
void (*NexSerial_readBuffer)(uint8_t*, size_t);

/**
 * @brief 
 * 
 */
void (*NexSerial_writeByte)(uint8_t);

/**
 * 
 * 
 */
uint8_t (*NexSerial_readByte)(void);

/**
 * @brief 
 * 
 */
size_t (*NexSerial_dataAvailable)(void);

/**
 * @brief 
 * 
 */
void (*NexSerial_flushBuffer)(void);

/**
 * @brief 
 * 
 */
void (*NexSerial_writeBuffer)(uint8_t *,size_t);

/**
 * @brief 
 * 
 * @return NexHardware_eventCallback 
 */
NexHardware_eventCallback NexHardware_autoWakeCallback;

/**
 * @brief 
 * 
 */
void *NexHardware_autoWakeCallbackPtr;

/**
 * @brief 
 * 
 * @return NexHardware_eventCallback 
 */
NexHardware_eventCallback NexHardware_autoSleepCallback;

/**
 * @brief 
 * 
 */
void *NexHardware_autoSleepCallbackPtr;


#pragma endregion

/**
 * @brief 
 * 
 */
char Nex_auxBuffer[12];  // TODO

/**
 * @brief 
 * 
 */
uint8_t Nex_txBuffer[64];   // TODO

/**
 * @brief 
 * 
 */
uint8_t Nex_rxBuffer[64];   // TODO

/**
 * @brief 
 */
uint8_t Nex_cmdBuffer[64]; // TODO

/**
 * @brief 
 * 
 */
NexReturnCode nex_retCode;

/**
 * @brief 
 * 
 * @param command 
 */
void NexHardware_sendCommand(const char *command);

/**
 * @brief 
 * @return 
 */
NexReturnCode NexHardware_init(void);

/**
 * @brief Wait for a response sequence from Nextion module
 * 
 * @return NexReturnCode 
 */
NexReturnCode NexHardware_waitResponse(void);

/**
 * @brief Receive a string
 * 
 * @param buffer Pointer to store the string
 * @param len Pointer to store length of received string 
 * @return true 
 * @return false 
 */
bool NexHardware_getString(char *buffer,size_t *len);

/**
 * @brief Receive a number
 * 
 * @param number 
 * @return true 
 * @return false 
 */
bool NexHardware_getNumber(uint32_t *number);

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
static bool NexHardware_validateEndSequence(void);

/**
 * @brief Immediate reset of Nextion device – reboot.
 * 
 */
void NexHardware_reset(void);

/**
 * @brief Sets Nextion mode between sleep and awake.
 * sleep=1 (Enter sleep mode) or sleep=0 (Exit sleep mode)
 * 
 * @param sleep 
 * @return NexReturnCode 
 */
NexReturnCode NexHardware_sleep(bool sleep);

/**
 * @brief Sets if Nextion should auto-wake from sleep when touch press occurs. min 0, max 1, default 0
 * thup=0 (do not wake), thup=1 (wake on touch)
 * @param autowake 
 * @return NexReturnCode 
 */
NexReturnCode NexHardware_setAutoWakeOnTouch(bool autowake);

/**
 * @brief Sets internal No-touch-then-sleep timer to specified value in seconds. min 3, max 65535, default 0 (max: 18 hours 12 minutes 15 seconds)
 * Nextion will auto-enter sleep mode if and when this timer expires. Note: Nextion device needs to exit sleep to issue thsp=0 to disable sleep
 * on no touch, otherwise once thsp is set, it will persist until reboot or reset.
 * 
 * @param sleep_interval 
 * @return NexReturnCode 
 */
NexReturnCode NexHardware_sleepOnNoTouch(uint16_t sleep_interval);

/**
 * @brief Sets the backlight level in percent min 0, max 100,
 * default 100 or user defined
 * 
 * @param backlight_level 
 * @return NexReturnCode 
 */
NexReturnCode NexHardware_setBacklightLevel(uint8_t backlight_level);

/**
 * @brief Sets the backlight level in percent, setting the current backlight level and saving it to be
 * the new power-on default backlight level, persisting until changed.
 * 
 * @param backlight_level 
 * @return NexReturnCode 
 */
NexReturnCode NexHardware_setBacklightLevelSave(uint8_t backlight_level);

/**
 * @brief Sets the Nextion Baud rate in bits-per-second min 2400, max 921600, default 9600 or user defined
 * Valid values are: 2400, 4800, 9600, 19200, 31250, 38400, 57600, and 115200, 230400, 250000, 256000, 512000, and 921600
 * 
 * @param baud_rate 
 * @return NexReturnCode 
 */
NexReturnCode NexHardware_setBaudRate(uint32_t baud_rate);

/**
 * @brief 
 * 
 * @param baud_rate 
 * @return NexReturnCode 
 */
NexReturnCode NexHardware_setBaudRateSave(uint32_t baud_rate);

/**
 * @brief 
 * 
 * @param nex_listenList 
 * @return NexReturnCode 
 */
NexReturnCode NexHardware_event(NexObject **nex_listenList);

/**
 * @brief 
 * 
 * @param page_id 
 * @param component_id 
 * @param event 
 */
void NexHardware_touchEvent(uint8_t *page_id, uint8_t *component_id, bool *event);

/**
 * @brief 
 * 
 * @param event 
 */
void NexHardware_sleepEvent(bool *event);

/**
 * @brief 
 * 
 * @param event 
 */
void NexHardware_autoWakeEvent(bool *event);

/**
 * @brief 
 * 
 */
void NexHardware_autoEnteredSleep(void);

/**
 * @brief 
 * 
 * @param eventCallback 
 */
void NexHardware_attachAutoWakeEvent(NexHardware_eventCallback eventCallback, void *ptr);

/**
 * @brief 
 * 
 */
void NexHardwawe_detachAutoWakeEvent(void);

/**
 * @brief 
 * 
 * @param eventCallback 
 */
void NexHardware_attachAutoSleepEvent(NexHardware_eventCallback eventCallback, void *ptr);

/**
 * @brief Deta
 * 
 */
void NexHardwawe_detachAutoSleepEvent(void);

#ifdef __cplusplus
}
#endif

#endif /*NEXHARDWARE_H*/
