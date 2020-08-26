/*
 * mFatFS.c
 *
 *  Created on: 18 août 2020
 *      Author: r.schluep
 */

#include "mFatFS.h"
#include "diskio.h"
#include <assert.h>


#include "ff.h"

static FATFS lFatfs[1];

/** update timer for the disk_io layer **/
static void sd_update(void)
{
}

/** mount the sd card. return 0 when successful **/
int32_t mFatFS_setup()
{
	return 0;
}

/** mount the usb stick. return 0 when successful **/
int32_t mFatFS_mount_usb_stick()
{
	// todo no usb driver yet present
	return -1;
}
