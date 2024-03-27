/* 
 * File:   Buzzer.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#ifndef __buzzer_h__
#define __buzzer_h__

#ifdef __cplusplus
extern "C" {
#endif

void initBuzzer(void);
void buzzer(bool enable);
void beepBuzzer(void);
void beepLongBuzzer(void);

#ifdef __cplusplus
}
#endif

#endif
