/*
 * mUtils.c
 *
 * contains all the utilities used by the project
 *
 *  Created on: 18 août 2020
 *      Author: r.schluep
 */

#include "mUtils.h"
#include <assert.h>
#include <stdio.h>


// holder for printf
/** application printf **/
char last_log[512];

/**
 * calculate the CRC of a given array of byte
 * @param buf the message where a CRC needs to be generated
 * @param len length of the message
 * @param lastCRC if first run, init to 0xFFFF. Else, give the last known CRC
 * @return the computed CRC with the byte a the correct order
 */
int16_t mUtils_calc_crc(uint8_t *buf, uint32_t len, uint16_t lastCRC)
{
	// swap crc byte
	uint16_t crc = (lastCRC >> 8) & 0x00FF;
	crc |= (lastCRC << 8) & 0xFF00;

	for (uint32_t pos = 0; pos < len; pos++)
	{
		crc ^= (uint16_t)buf[pos]; // XOR byte into least sig. byte of crc

		int i;
		for (i = 8; i != 0; i--)
		{ // Loop over each bit
			if ((crc & 0x0001) != 0)
			{              // If the LSB is set
				crc >>= 1; // Shift right and XOR 0xA001
				crc ^= 0xA001;
			}
			else
				// Else LSB is not set
				crc >>= 1; // Just shift right
		}
	}

	// swap crc
	uint16_t temp_crc = crc;
	crc = (temp_crc >> 8) & 0x00FF;
	crc |= (temp_crc << 8) & 0xFF00;

	return crc;
}

/** set the crc value of the message **/
void mUtils_set_crc(uint8_t *buf, uint32_t size)
{
	assert(size > 2); // len of buffer must be at least 3 bytes

	uint16_t crc = mUtils_calc_crc(buf, size - 2, 0xFFFF);
	buf[size - 1] = (crc >> 8) & 0xFF;
	buf[size - 2] = crc & 0xFF;
}

/** extract the crc value from a message **/
uint16_t mUtils_get_crc(uint8_t *buf, uint32_t size)
{
	uint16_t lReturn = 0;

	assert(size > 2); // len of buffer must be at least 3 bytes

	lReturn = ((uint16_t)(buf[size - 1]) << 8);
	lReturn |= buf[size - 2];

	return lReturn;
}
