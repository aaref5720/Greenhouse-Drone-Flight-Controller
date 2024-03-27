/* 
 * File:   PID.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#ifndef __pid_h__
#define __pid_h__

#ifdef __cplusplus
extern "C" {
#endif

#include "LowPassFilter.h"

// From Arduino source code
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

typedef struct {
    float Kp, Ki, Kd; // PID variables
    float integrationLimit;
    float Fc; // Cutoff frequency in Hz
} pid_values_t;

typedef struct {
    pid_values_t *values; // Use pointer to pid_values_t struct that are saved in the EEPROM
    float iTerm, lastError;
    low_pass_t low_pass; // First order low-pass filter for the D-term
} pid_t;

void initPID(void);
float updatePID(pid_t *pid, float setpoint, float input, float dt);
void resetPIDRollPitchYaw(void);
void resetPIDAltHold(void);

extern pid_t pidRoll, pidPitch, pidYaw, pidSonarAltHold, pidBaroAltHold;

#ifdef __cplusplus
}
#endif

#endif
