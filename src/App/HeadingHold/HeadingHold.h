/* 
 * File:   HeadingHold.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#if !defined(__headinghold_h__) && USE_MAG
#define __headinghold_h__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

float updateHeadingHold(angle_t *angle, float rudder, uint32_t now);
void resetHeadingHold(angle_t *angle);

#ifdef __cplusplus
}
#endif

#endif
