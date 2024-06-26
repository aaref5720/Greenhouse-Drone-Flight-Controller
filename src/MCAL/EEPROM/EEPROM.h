/* 
 * File:   EEPROM.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#ifndef __eeprom_h__
#define __eeprom_h__

#include "PID.h"
#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    // Can be set by the user
    pid_values_t pidRollPitchValues, pidYawValues; // Use same PID values for both pitch and roll, but different values for yaw
    pid_values_t pidSonarAltHoldValues, pidBaroAltHoldValues; // PID values for altitude hold
    float angleKp; // Self level mode Kp value
    float headKp; // Heading mode Kp value
    uint8_t maxAngleInclination; // Max angle in self level mode
    uint8_t maxAngleInclinationDistSensor; // Max angle when using sonar or LIDAR-Lite v3 in altitude hold mode
    float stickScalingRollPitch, stickScalingYaw; // Stick scaling values

    // Will be set by the microcontroller
    bool calibrateESCs; // Flag used to tell if it should calibrate ESCs at next power cycle
    sensorRaw_t accZero; // Accelerometer calibration values
    sensor_t magZero; // Magnetometer calibration values
    bool configureBtModule; // Used in order to configure the Bluetooth module the first time it is powered on
} config_t;

extern config_t cfg;

void initEEPROM(void);
void setDefaultConfig(void);
void updateConfig(void);

#ifdef __cplusplus
}
#endif

#endif
