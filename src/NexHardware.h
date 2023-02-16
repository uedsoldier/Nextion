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
#pragma region

/**
 * @brief
 *
 */
#define NEXTION_USE_CRC 1

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
    NEX_RETCODE_ERROR
} NexReturnCode;

#pragma region Callback definitions
uint8_t (*NexSerial_readByteBuffer)(void);
uint16_t (*NexSerial_readBytes)(void *, uint16_t);
void (*NexSerial_writeByte)(void);
uint16_t (*NexSerial_dataAvailable)(void);
void (*NexSerial_print)(uint8_t *);
#pragma endregion

uint8_t Nex_txBuffer[64];   // TODO

NexReturnCode Nex_sendCommand(char *command);
inline void NexHardware_clear_txBuffer();

#ifdef __cplusplus
}
#endif

#endif /*NEXHARDWARE_H*/
