/*----------------------------------------------------------------------------/
/  FatFs - Generic FAT Filesystem Module  R0.14                               /
/-----------------------------------------------------------------------------/
/
/ Copyright (C) 2019, ChaN, all right reserved.
/
/ FatFs module is an open source software. Redistribution and use of FatFs in
/ source and binary forms, with or without modification, are permitted provided
/ that the following condition is met:
/
/ 1. Redistributions of source code must retain the above copyright notice,
/    this condition and the following disclaimer.
/
/ This software is provided by the copyright holder and contributors "AS IS"
/ and any warranties related to this software are DISCLAIMED.
/ The copyright owner or contributors be NOT LIABLE for any damages caused
/ by use of this software.
/
/----------------------------------------------------------------------------*/

#include "ff.h"     /* Declarations of FatFs API */
#include "diskio.h" /* Declarations of device I/O functions */

FRESULT f_open(FIL *fp, const TCHAR *path, BYTE mode)
{
	return FR_OK;
} /* Open or create a file */
FRESULT f_close(FIL *fp)
{
	return FR_OK;
}
FRESULT f_read(FIL *fp, void *buff, UINT btr, UINT *br)
{
	return FR_OK;
}
FRESULT f_write(FIL *fp, const void *buff, UINT btw, UINT *bw)
{
	return FR_OK;
}
FRESULT f_lseek(FIL *fp, FSIZE_t ofs)
{
	return FR_OK;
}
FRESULT f_truncate(FIL *fp)
{
	return FR_OK;
}
FRESULT f_sync(FIL *fp)
{
	return FR_OK;
}
FRESULT f_opendir(DIR *dp, const TCHAR *path)
{
	return FR_OK;
}
FRESULT f_closedir(DIR *dp)
{
	return FR_OK;
}
FRESULT f_readdir(DIR *dp, FILINFO *fno)
{
	return FR_OK;
}
FRESULT f_findfirst(DIR *dp, FILINFO *fno, const TCHAR *path,
                    const TCHAR *pattern)
{
	return FR_OK;
}
FRESULT f_findnext(DIR *dp, FILINFO *fno)
{
	return FR_OK;
}
FRESULT f_mkdir(const TCHAR *path)
{
	return FR_OK;
}
FRESULT
f_unlink(const TCHAR *path)
{
	return FR_OK;
}
FRESULT
f_rename(const TCHAR *path_old, const TCHAR *path_new)
{
	return FR_OK;
}
FRESULT f_stat(const TCHAR *path, FILINFO *fno)
{
	return FR_OK;
}
FRESULT f_chmod(const TCHAR *path, BYTE attr, BYTE mask)
{
	return FR_OK;
}
FRESULT f_utime(const TCHAR *path, const FILINFO *fno)
{
	return FR_OK;
}
FRESULT f_chdir(const TCHAR *path)
{
	return FR_OK;
}
FRESULT f_chdrive(const TCHAR *path)
{
	return FR_OK;
}
FRESULT f_getcwd(TCHAR *buff, UINT len)
{
	return FR_OK;
}
FRESULT
f_getfree(const TCHAR *path, DWORD *nclst, FATFS **fatfs)
{
	return FR_OK;
}
FRESULT f_getlabel(const TCHAR *path, TCHAR *label, DWORD *vsn)
{
	return FR_OK;
}
FRESULT f_setlabel(const TCHAR *label)
{
	return FR_OK;
}
FRESULT f_forward(FIL *fp, UINT (*func)(const BYTE *, UINT), UINT btf, UINT *bf)
{
	return FR_OK;
}
FRESULT f_expand(FIL *fp, FSIZE_t fsz, BYTE opt)
{
	return FR_OK;
}
FRESULT f_mount(FATFS *fs, const TCHAR *path, BYTE opt)
{
	return FR_OK;
}
FRESULT f_mkfs(const TCHAR *path, const MKFS_PARM *opt, void *work, UINT len)
{
	return FR_OK;
}
FRESULT
f_fdisk(BYTE pdrv, const LBA_t ptbl[], void *work)
{
	return FR_OK;
}
FRESULT f_setcp(WORD cp)
{
	return FR_OK;
}
int f_putc(TCHAR c, FIL *fp)
{
	return FR_OK;
}
int f_puts(const TCHAR *str, FIL *cp)
{
	return 0;
}
int f_printf(FIL *fp, const TCHAR *str, ...)
{
	return 0;
}
TCHAR *f_gets(TCHAR *buff, int len, FIL *fp)
{
	return buff;
}