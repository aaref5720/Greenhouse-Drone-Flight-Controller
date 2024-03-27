/* 
 * File:   IMU.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#ifndef __imu_h__
#define __imu_h__

#include "MPU6500.h"

#define DEG_TO_RAD  0.017453292519943295769236907684886f
#define RAD_TO_DEG  57.295779513082320876798154814105f

#ifdef __cplusplus
extern "C" {
#endif

void getAngles(mpu6500_t *mpu6500, sensor_t *mag, angle_t *angle, float dt);
void rotateV(sensor_t *v, const angle_t *angle);

#ifdef __cplusplus
}
#endif

#endif
