/* 
 * File:   Types.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */


#ifndef __types_h__
#define __types_h__

#ifdef __cplusplus
extern "C" {
#endif

typedef union {
    struct {
        int16_t X, Y, Z;
    } __attribute__((packed)) axis;
    int16_t data[3];
} sensorRaw_t;

typedef union {
    struct {
        float X, Y, Z;
    } __attribute__((packed)) axis;
    float data[3];
} sensor_t;

typedef union {
    struct {
        float roll, pitch, yaw;
    } __attribute__((packed)) axis;
    float data[3];
} angle_t;

#ifdef __cplusplus
}
#endif

#endif
