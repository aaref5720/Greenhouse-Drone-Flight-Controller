/* 
 * File:   PID.c
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#include <stdint.h>
#include <stdbool.h>

#include "EEPROM.h"
#include "PID.h"

pid_t pidRoll, pidPitch, pidYaw, pidSonarAltHold, pidBaroAltHold;

void initPID(void) {
    // Set PID values to point at values read from EEPROM
    pidRoll.values = &cfg.pidRollPitchValues;
    pidPitch.values = &cfg.pidRollPitchValues;
    pidYaw.values = &cfg.pidYawValues;
    pidSonarAltHold.values = &cfg.pidSonarAltHoldValues;
    pidBaroAltHold.values = &cfg.pidBaroAltHoldValues;
}

float updatePID(pid_t *pid, float setpoint, float input, float dt) {
    float error = setpoint - input;

    // P-term
    float pTerm = pid->values->Kp * error;

    // I-term
    // Use Trapezoidal Integration, see: http://ecee.colorado.edu/shalom/Emulations.pdf
    pid->iTerm += pid->values->Ki * (error + pid->lastError) / 2.0f * dt; // Multiplication with Ki is done before integration limit, to make it independent from integration limit value
    pid->iTerm = constrain(pid->iTerm, -pid->values->integrationLimit, pid->values->integrationLimit); // Limit the integrated error - prevents windup

    // D-term
    float deltaError = (error - pid->lastError) / dt; // Calculate difference and compensate for difference in time by dividing by dt
    pid->lastError = error;

    // Use exponential smoothing on the derivative to reduce the impact of noise: https://en.wikipedia.org/wiki/Exponential_smoothing
    pid->low_pass.Fc = pid->values->Fc; // Set cutoff-frequency in case it has changed
    float derivative = applyLowPass(&pid->low_pass, deltaError, dt);
    float dTerm = pid->values->Kd * derivative;

    return pTerm + pid->iTerm + dTerm; // Return sum
}

void resetPIDRollPitchYaw(void) {
    pidRoll.iTerm = pidRoll.lastError = pidRoll.low_pass.prevOutput = 0.0f;
    pidPitch.iTerm = pidPitch.lastError = pidPitch.low_pass.prevOutput = 0.0f;
    pidYaw.iTerm = pidYaw.lastError = pidYaw.low_pass.prevOutput = 0.0f;
}

void resetPIDAltHold(void) {
    pidSonarAltHold.iTerm = pidSonarAltHold.lastError = pidSonarAltHold.low_pass.prevOutput = 0.0f;
    pidBaroAltHold.iTerm = pidBaroAltHold.lastError = pidBaroAltHold.low_pass.prevOutput = 0.0f;
}
