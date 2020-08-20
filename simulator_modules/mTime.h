/*
 * mTime.h
 *
 *  Created on: 17 aoรปt 2020
 *      Author: r.schluep
 */

#ifndef MODULE_MTIME_H_
#define MODULE_MTIME_H_

#include <stdint.h>
#include <time.h>

/** mTime setup. used to configure the RTC peripheral **/
int32_t mTime_setup();

/** set the time in the RTC using a given unix time stamp **/
int32_t mTime_set_time_unix64(uint64_t unix_time);

/** set the time in the RTC using a standard struct tm **/
int32_t mTime_set_time_tm(struct tm *std_time);

/** get the time in unix time stamp format **/
uint64_t mTime_get_time_unix64();

/** get the time in struct tm format **/
void mTime_get_time_tm(struct tm *std_time);

/** transform tm to unixtime **/
uint64_t mTime_unix64_from_tm(struct tm std_time);

/** transform unix64 to tm**/
struct tm mTime_tm_from_unix64(uint64_t unix_time);

/**
 * calibrate the LPC1788 RTC by giving the actual time. This function
 * also set the current RTC time
 * @param real_unix_time the correct current time
 * @param calib_period time in second since last time set (or calibrated)
 */
void mTime_calibrate_cb(uint64_t real_unix_time, uint32_t calib_period);

#endif /* MODULE_MTIME_H_ */
