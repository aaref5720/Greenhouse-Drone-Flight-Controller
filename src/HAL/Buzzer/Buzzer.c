/* 
 * File:   Buzzer.c
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#include <stdint.h>
#include <stdbool.h>

#include "Buzzer.h"
#include "Config.h"
#include "Time.h"

#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

void initBuzzer(void) {
    SysCtlPeripheralEnable(SYSCTL_PERIPH_BUZZER); // Enable peripheral
    SysCtlDelay(2); // Insert a few cycles after enabling the peripheral to allow the clock to be fully activated
    GPIOPinTypeGPIOOutput(GPIO_BUZZER_BASE, GPIO_PIN_BUZZER);
}

inline void buzzer(bool enable) {
    GPIOPinWrite(GPIO_BUZZER_BASE, GPIO_PIN_BUZZER, enable ? GPIO_PIN_BUZZER : 0);
}

void beepBuzzer(void) {
    buzzer(true);
    delay(100);
    buzzer(false);
}

void beepLongBuzzer(void) {
    buzzer(true);
    delay(1000);
    buzzer(false);
}
