/* 
 * File:   BMP180.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#if !defined(__bmp180_h__) && USE_BARO
#define __bmp180_h__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int16_t AC1;
    int16_t AC2;
    int16_t AC3;
    uint16_t AC4;
    uint16_t AC5;
    uint16_t AC6;
    int16_t B1;
    int16_t B2;
    // The MB calibration value is never used
    int16_t MC;
    int16_t MD;
} bmp180_cal_t;

typedef struct {
    int32_t pressure; // Pressure in Pa
    int32_t temperature; // Temperature in 0.1 C
    float absoluteAltitude; // Absolute altitude in cm
    float groundAltitude; // Ground altitude in cm
    uint8_t mode; // The oversampling mode to be used by the BMP180
    bmp180_cal_t cal; // Calibration data
} bmp180_t;

void initBMP180(bmp180_t *bmp180);
bool getBMP180Data(bmp180_t *bmp180);

#ifdef __cplusplus
}
#endif

#endif
