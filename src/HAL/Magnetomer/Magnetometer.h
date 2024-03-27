/* 
 * File:   Magnetomer.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#if !defined(__magnetometer_h__) && USE_MAG
#define __magnetometer_h__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void initMag(void);
bool getMagData(sensor_t *mag, bool calibrating);
void calibrateMag(void);

#ifdef __cplusplus
}
#endif

#endif
