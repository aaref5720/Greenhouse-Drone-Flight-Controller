/* 
 * File:   AK8963.c
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#if !defined(__ak8963_h__) && USE_MAG
#define __ak8963_h__

#include <stdbool.h>

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

bool initAK8963(void);
bool dataReadyAK8963(void);
void getAK8963Data(sensor_t *mag, bool calibrating);

#ifdef __cplusplus
}
#endif

#endif
