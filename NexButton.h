/**
 * @file NexButton.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NEXBUTTON_H
#define NEXBUTTON_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "NexTouch.h"
#include "NexHardware.h"
#include "NexObject.h"
#include "NexWidget.h"

/**
 * @brief 
 * 
 */
typedef struct _NexButton{
    NexObject object;   // Basic component (type, id, page id, object name, component scope)
    

} NexButton;


#ifdef __cplusplus
}
#endif

#endif /*NEXBUTTON_H*/
