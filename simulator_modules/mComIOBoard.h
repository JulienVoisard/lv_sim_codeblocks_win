/*
 * mComIOBoard.h
 *
 *  Created on: 18 août 2020
 *      Author: r.schluep
 */

#include <stdint.h>
#include <stdbool.h>

#ifndef MODULE_MCOMIOBOARD_H_
#define MODULE_MCOMIOBOARD_H_

#define HOSTNAME_MAX_LENGTH 16
#define MAC_ADDRESS_LENGTH 6
#define IP_LENGTH 16

/** network info, used by ESP32 **/
typedef struct
{
	char hostname[HOSTNAME_MAX_LENGTH];
	uint8_t macAddress[MAC_ADDRESS_LENGTH];
	char ip[IP_LENGTH];
} Network_Info_t;

/** opcua data, used by the ESP32 **/
typedef struct
{
	uint64_t piece_done;
	int32_t perte_code;
	int32_t status;
	int32_t machine_setup;
} Opcua_t;

/** com lcd structure **/
typedef struct
{
	uint32_t input;
	uint32_t output;
	uint16_t analog_in_1;
	uint16_t analog_in_2;
	uint16_t analog_out_1;
	uint16_t analog_out_2;
	uint64_t time;
	Opcua_t opcua;
	Network_Info_t net;
	uint16_t bat_voltage;
	uint16_t crc;
} Com_Lcd_t;


/** get the inputs **/
uint32_t mComIOBoard_get_inputs();

/** get the encoder input **/
uint16_t mComIOBoard_get_encoder();

/** get the second analog input **/
uint16_t mComIOBoard_get_analog_input_2();

/** get the IO_Board time **/
uint64_t mComIOBoard_get_time();

/** say if the machine is in setup **/
bool mComIOBoard_is_machine_setup();

/** get the network information **/
Network_Info_t mComIOBoard_get_net_info();

/** get current battery voltage **/
uint16_t mComIOBoard_get_bat_voltage();

/** set the outputs values. return 0 if queue send is completed **/
void mComIOBoard_set_digital_outputs(uint32_t outputs);

/** set the analog outputs 1 **/
void mComIOBoard_set_analog_output_1(uint32_t a_output);

/** set the analog outputs 2 **/
void mComIOBoard_set_analog_output_1(uint32_t a_output);

/** set the opcua data in the ESP32 **/
void mComIOBoard_set_opcua(Opcua_t *pOpcua);

/** set the hostname in the ESP32 **/
void mComIOBoard_set_hostname(char *p_hostname);

#endif /* MODULE_MCOMIOBOARD_H_ */
