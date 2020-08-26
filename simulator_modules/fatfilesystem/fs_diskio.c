/*-----------------------------------------------------------------------*/
/* Low level disk I/O module                                             */
/* (C) Copyright 2007,2008                                               */
/* Martin Thomas, Lorenz Aebi                                            */
/*-----------------------------------------------------------------------*/
/* This is a LPC23xx/24xx MCI disk I/O module                            */
/*-----------------------------------------------------------------------*/

// Add Multi Block Write by Lorenz Aebi 2008
// Bugfix from Marco Ziegert 20090823
// #define DISKIO_DEBUG
// #define DISKIO_DUMPSTAT
// #define DISKIO_DEBUGR
// #define DISKIO_DEBUGW
#include "diskio.h"
#include <string.h>

//#include "irq.h"
//#include "target.h"

#include <stdarg.h>
#include <stdio.h>

void DBG_PrintImpl(char *format, ...)
{
}

static void dump_status(const char *info)
{
}

static uint16_t currstate_from_status(uint32_t st)
{
	return 0;
}

static uint8_t status_ready_bit(uint32_t st)
{
	return 0;
}

// state to trans (SD Card State Diagram: V2.2 P4-7)
static void SELECT(void)
{
}

// state to stby
static void DESELECT(void)
{
	/*uint32_t cardtype_save, st, currst;

	Timer2 = 500;
	do
	{
		MCI_GetCardStatus(&st);

		currst = currstate_from_status(st);
	} while ((currst != CURR_STATE_TRAN) && (currst != CURR_STATE_STBY) &&
	         Timer2);

	if (Timer2 == 0)
	{
		diskio_printf("DESELCT timeout waiting trans or stby\n\r");
	}
	else if (currst == CURR_STATE_TRAN)
	{
		cardtype_save = MCI_CardType;
		// CMD7: trans to stby (RCA 0) / de-select
		MCI_CardType = 0;
		if (MCI_Cmd_SelectCard() != MCI_FUNC_OK)
		{
			diskio_printf("DESELECT failed\n\r");
		}
		MCI_CardType = cardtype_save;
	}
	else
	{
		//diskio_printf("DSELECT already in stby\n\r");
	}

	return;*/
}

// wait for stby or trans with timeout
static uint8_t wait_ready(void)
{
}

// well, no SPI used here but will keep the interface compatible with
// Chan's examples
static void release_spi(void)
{
}

static void power_off(void)
{
	SELECT();
	wait_ready();
	release_spi();

	// TODO	MCI_Power_Off();
}

static int MCI_disk_initialize(void)
{
}

/*-----------------------------------------------------------------------*/
/* Initialize a Drive                                                    */

DSTATUS disk_initialize(uint8_t drv /* Physical drive nmuber (0..) */
)
{
}

/*-----------------------------------------------------------------------*/
/* Return Disk Status                                                    */

DSTATUS disk_status(uint8_t drv /* Physical drive nmuber (0..) */
)
{
	return STA_NOINIT;
}

/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */

DRESULT disk_read(uint8_t drv,   /* Physical drive number (0..) */
                  uint8_t *buff, /* Data buffer to store read data */
                  uint32_t s,    /* Sector number (LBA) */
                  uint8_t count  /* Sector count (1..255) */
)
{
}

/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */

DRESULT disk_write(uint8_t drv,         /* Physical drive number (0..) */
                   const uint8_t *buff, /* Data to be written */
                   uint32_t sector,     /* Sector number (LBA) */
                   uint8_t count        /* Sector count (1..255) */
)
{
	//uint16_t k;
	return RES_PARERR;
}

/*-----------------------------------------------------------------------*/
/* Device Timer Interrupt Procedure  (Platform dependent)                */
/*-----------------------------------------------------------------------*/
/* This function must be called in period of 1ms                         */

void disk_timerproc(void)
{
}

uint32_t get_fattime(void)
{
	return 0;
}
