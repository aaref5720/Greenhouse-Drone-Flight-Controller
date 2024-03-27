/* 
 * File:   UART.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */


#if !defined(__uart_h__) && UART_DEBUG
#define __uart_h__

#ifdef __cplusplus
extern "C" {
#endif

void initUART(void);
void printPIDValues(pid_values_t *pid);
void printSettings(void);

#ifdef __cplusplus
}
#endif

#endif
