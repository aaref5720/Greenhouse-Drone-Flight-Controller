/* 
 * File:   Time.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#ifndef __time_h__
#define __time_h__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void initTime(void);
void delay(uint32_t ms);
void delayMicroseconds(uint32_t us);
uint32_t millis(void);
uint32_t micros(void);

#ifdef __cplusplus
}
#endif

#endif
