/* 
 * File:   PPM.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#ifndef __ppm_h__
#define __ppm_h__

#ifdef __cplusplus
extern "C" {
#endif

// Internal motor values are in the range [-100:100]
#define MIN_MOTOR_OUT (-100.0f)
#define MAX_MOTOR_OUT (100.0f)

void initPPM(void);
void writePPMAllOff(void);
void updateMotorsAll(float *values);

float mapf(float x, float in_min, float in_max, float out_min, float out_max);

#ifdef __cplusplus
}
#endif

#endif
