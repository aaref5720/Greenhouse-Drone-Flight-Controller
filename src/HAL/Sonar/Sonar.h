/* 
 * File:   Sonar.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#if !defined(__sonar_h__) && USE_SONAR
#define __sonar_h__

#ifdef __cplusplus
extern "C" {
#endif

#include "Types.h"

void initSonar(void);
bool triggerSonar(void);

#if USE_BARO
int16_t getSonarDistance(angle_t *angle, int32_t temperature);
#else
int16_t getSonarDistance(angle_t *angle);
#endif

#ifdef __cplusplus
}
#endif

#endif
