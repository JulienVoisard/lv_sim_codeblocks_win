#include "mTime.h"
#include "stdint.h"
#include "stdio.h"
#include "time.h"

/** mTime setup. used to configure the RTC peripheral **/
int32_t mTime_setup()
{
}

/** set the time in the RTC using a given unix time stamp **/
int32_t mTime_set_time_unix64(uint64_t unix_time)
{
}

/** set the time in the RTC using a standard struct tm **/
int32_t mTime_set_time_tm(struct tm *std_time)
{
}

/** get the time in unix time stamp format **/
uint64_t mTime_get_time_unix64()
{
	return time(NULL);
}

/** get the time in struct tm format **/
void mTime_get_time_tm(struct tm *std_time)
{
	memcpy(std_time, localtime(time(NULL)), sizeof(struct tm));
}

/**
 * calibrate the LPC1788 RTC by giving the actual time. This function
 * also set the current RTC time
 * @param real_unix_time the correct current time
 * @param calib_period time in second since last time set (or calibrated)
 */
void mTime_calibrate_cb(uint64_t real_unix_time, uint32_t calib_period)
{
}
