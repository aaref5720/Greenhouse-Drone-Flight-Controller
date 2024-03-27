/* 
 * File:   I2C.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */


#ifndef __i2c_h__
#define __i2c_h__

#ifdef __cplusplus
extern "C" {
#endif

void initI2C(void);
void i2cWrite(uint8_t addr, uint8_t regAddr, uint8_t data);
void i2cWriteData(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t length);
uint8_t i2cRead(uint8_t addr, uint8_t regAddr);
void i2cReadData(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t length);

#ifdef __cplusplus
}
#endif

#endif
