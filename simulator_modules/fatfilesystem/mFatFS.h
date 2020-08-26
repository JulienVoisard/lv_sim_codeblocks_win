/*
 * mFatFS.h
 *
 * this module provide an standard interface to get useful information
 * about what drive is mounted and which are not
 *
 *  Created on: 18 août 2020
 *      Author: r.schluep
 */

#ifndef FATFILESYSTEM_MFATFS_H_
#define FATFILESYSTEM_MFATFS_H_

#include <stdint.h>
#include <stdbool.h>

/** mount the sd card. return 0 when successful **/
int32_t mFatFS_setup();

/** mount the usb stick. return 0 when successful **/
int32_t mFatFS_mount_usb_stick();

#endif /* FATFILESYSTEM_MFATFS_H_ */
