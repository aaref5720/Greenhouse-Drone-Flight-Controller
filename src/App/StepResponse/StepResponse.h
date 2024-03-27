/* 
 * File:   StepResponse.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#if !defined(__logger_h__) && (STEP_ACRO_SELF_LEVEL || STEP_ALTITUDE_HOLD || STEP_HEADING_HOLD)
#define __logger_h__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

float stepResponse(bool active, float setpoint, float input, float step1, float step2, uint32_t interval, uint32_t now);

#ifdef __cplusplus
}
#endif

#endif
