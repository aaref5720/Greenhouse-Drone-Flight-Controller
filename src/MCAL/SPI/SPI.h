/* 
 * File:   SPI.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */


#if !defined(__spi_h__) && USE_FLOW_SENSOR
#define __spi_h__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void initSPI(void);

void spiWrite(uint8_t regAddr, uint8_t data);
void spiWriteData(uint8_t regAddr, const uint8_t *data, uint32_t length);

uint8_t spiRead(uint8_t regAddr);
void spiReadData(uint8_t regAddr, uint8_t *data, uint32_t length);

void spiTransfer(const uint8_t *header, uint16_t headerLength, const uint8_t *sendData, uint8_t *recvData, uint32_t dataLength);

#ifdef __cplusplus
}
#endif

#endif
