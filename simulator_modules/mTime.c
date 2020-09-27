#include "mTime.h"
#include "stdint.h"
#include "stdio.h"
#include "time.h"
#include "string.h"

/** mTime setup. used to configure the RTC peripheral **/
int32_t mTime_setup()
{
    return 0;
}

/** set the time in the RTC using a given unix time stamp **/
int32_t mTime_set_time_unix64(uint64_t unix_time)
{
    return 0;
}

/** set the time in the RTC using a standard struct tm **/
int32_t mTime_set_time_tm(struct tm *std_time)
{
    return 0;
}

/** get the time in unix time stamp format **/
uint64_t mTime_get_time_unix64()
{
	return time(NULL);
}

/** get the time in struct tm format **/
void mTime_get_time_tm(struct tm *std_time)
{
    struct tm tmp_tm = mTime_tm_from_unix64(time(NULL));
	memcpy(std_time, &tmp_tm, sizeof(struct tm));
}

/** transform tm to unixtime **/
uint64_t mTime_unix64_from_tm(struct tm std_time)
{
    std_time.tm_year -= 1900;
    return mktime(&std_time);
}

/** transform unix64 to tm**/
struct tm mTime_tm_from_unix64(uint64_t unix_time){
    struct tm tm_time = *localtime(&unix_time);
	tm_time.tm_year +=1900;
	return tm_time;
};


/**
 * calibrate the LPC1788 RTC by giving the actual time. This function
 * also set the current RTC time
 * @param real_unix_time the correct current time
 * @param calib_period time in second since last time set (or calibrated)
 */
void mTime_calibrate_cb(uint64_t real_unix_time, uint32_t calib_period)
{
}
