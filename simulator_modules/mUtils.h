/*
 * mUtils.h
 *
 *  Created on: 18 août 2020
 *      Author: r.schluep
 */

#ifndef MODULE_MUTILS_H_
#define MODULE_MUTILS_H_

#include <stdint.h>

/** define MIN, MAX and ABS macro for the priject **/
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ABS(a)    (((a) < (0)) ? (-a) : (a))

#include <stdio.h>
extern char last_log[512];
#define cmd_print(...) snprintf(last_log, 512, __VA_ARGS__)

/**
 * calculate the CRC of a given array of byte
 * @param buf the message where a CRC needs to be generated
 * @param len length of the message
 * @param lastCRC if first run, init to 0xFFFF. Else, give the last known CRC
 * @return the computed CRC with the byte a the correct order
 */
int16_t mUtils_calc_crc(uint8_t *buf, uint32_t len, uint16_t lastCRC);

/** set the crc value of the message **/
void mUtils_set_crc(uint8_t *buf, uint32_t size);

/** extract the crc value from a message **/
uint16_t mUtils_get_crc(uint8_t *buf, uint32_t size);

#endif /* MODULE_MUTILS_H_ */
