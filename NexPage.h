/**
 * @file NexPage.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NEXPAGE_H
#define NEXPAGE_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "NexTouch.h"
#include "NexHardware.h"

#define NEX_PAGE_PARAMETER_LEVEL 0

/**
 * @brief 
 * 
 */
typedef struct _NexPage{
    NexObject object_base_parameters;   // Basic parameters of component (type, id, page id, object name, component scope)
    static uint16_t w;                  // Width (read-only at runtime)
    static uint16_t h;                  // Height (read-only at runtime)
    #if defined(NEX_PAGE_PARAMETER_LEVEL) && (NEX_PAGE_PARAMETER_LEVEL > 0)
    uint8_t up;                         // Scroll up page ID (No scrolling page:255)
    uint8_t down;                       // Scroll down page ID (No scrolling page:255)
    uint8_t left;                       // Scroll left page ID (No scrolling page:255)
    uint8_t right;                      // Scroll right page ID (No scrolling page:255)
    #endif

    
} NexPage;


#ifdef __cplusplus
}
#endif

#endif /*NEXPAGE_H*/