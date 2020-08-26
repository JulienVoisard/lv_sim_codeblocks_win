/*
 * mComIOBoard.c
 *
 * Communication with the external IO board file definition
 * At the moment, only the SPI communication is available
 *
 *  Created on: 18 août 2020
 *      Author: r.schluep
 */

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "mComIOBoard.h"
#include "mTime.h"

uint32_t s_angle = 0;

/** master SPI update function **/
static void mComIOBoard_task(void)
{
}

/** get the inputs **/
uint32_t mComIOBoard_get_inputs()
{
	return 0;
}

/** get the encoder input **/
uint16_t mComIOBoard_get_encoder()
{
	++s_angle;
	s_angle = s_angle % 3600;
	return s_angle / 10;
}

/** get the second analog input **/
uint16_t mComIOBoard_get_analog_input_2()
{
	return 0;
}

/** get the IO_Board time **/
uint64_t mComIOBoard_get_time()
{
	return mTime_get_time_unix64();
}

/** say if the machine is in setup **/
bool mComIOBoard_is_machine_setup()
{
	return false;
}

Network_Info_t network_info = {0};

/** get the network information **/
Network_Info_t mComIOBoard_get_net_info()
{
	return network_info;
}

/** get current battery voltage **/
uint16_t mComIOBoard_get_bat_voltage()
{
	return 12;
}

/** set the outputs values. return 0 if queue send is completed **/
void mComIOBoard_set_digital_outputs(uint32_t outputs)
{
}

/** set the analog outputs 1 **/
void mComIOBoard_set_analog_output_1(uint32_t a_output)
{
}

/** set the analog outputs 2 **/
void mComIOBoard_set_analog_output_2(uint32_t a_output)
{
}

/** set the opcua data in the ESP32 **/
void mComIOBoard_set_opcua(Opcua_t *pOpcua)
{
}

/** set the hostname in the ESP32 **/
void mComIOBoard_set_hostname(char *p_hostname)
{
	assert(p_hostname);
	strncpy(network_info.hostname, p_hostname, HOSTNAME_MAX_LENGTH);
}

/**
 * mComIOBoard initialization
 * @return 0 if initialization succeed
 */
uint32_t mComIOBoard_setup(void)
{

	// if we are here, everithing is fine
	return 0;
}
