/* 
 * File:   LowPassFilter.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#ifndef __low_pass_filter__
#define __low_pass_filter__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float prevOutput, Fc; // Previous output and cutoff frequency in Hz
} low_pass_t;

float applyLowPass(low_pass_t *low_pass, float input, float dt);

#ifdef __cplusplus
}
#endif

#endif
