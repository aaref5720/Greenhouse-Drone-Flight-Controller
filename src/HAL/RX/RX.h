/* 
 * File:   RX.h
 * Author: Abdelrahman Aref
 * Email: abdo01445@gmail.com
 */

#ifndef __rx_h__
#define __rx_h__

#ifdef __cplusplus
extern "C" {
#endif

// Used to check for min and max value of a specific channel
#define CHANNEL_MIN_CHECK (-95.0f)
#define CHANNEL_MAX_CHECK (95.0f)

typedef enum {
    RX_AILERON_CHAN = 0,
    RX_ELEVATOR_CHAN,
    RX_THROTTLE_CHAN,
    RX_RUDDER_CHAN,
    RX_AUX1_CHAN,
    RX_AUX2_CHAN,
    RX_NUM_CHANNELS,
} rxChannel_e;

void initRX(void);
float getRXChannel(rxChannel_e channel);

extern volatile bool validRXData;

#ifdef __cplusplus
}
#endif

#endif
