/* 
 * File:   AltitudeHold.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */


#if !defined(__altitude_h__) && (USE_SONAR || USE_BARO || USE_LIDAR_LITE)
#define __altitude_h__

#include "MPU6500.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
#if USE_BARO
    float altitude, velocity, acceleration; // Values are in cm
    float altitudeLpf; // Low-pass filtered altitude estimate
#endif
#if USE_SONAR
    int16_t sonarDistance; // Distance in mm
#endif
#if USE_LIDAR_LITE
    int32_t lidarLiteDistance; // Distance in mm
#endif
#if USE_SONAR || USE_LIDAR_LITE
    float distance; // Fusioned distance from sonar and LIDAR-Lite v3 in mm
#endif
} altitude_t;

void initAltitudeHold(void);
void getAltitude(angle_t *angle, mpu6500_t *mpu6500, altitude_t *altitude, uint32_t now, float dt);
float updateAltitudeHold(float aux, altitude_t *altitude, float throttle, uint32_t now, float dt);
void resetAltitudeHold(altitude_t *altitude);

#ifdef __cplusplus
}
#endif

#endif
