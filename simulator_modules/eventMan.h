/*
 * eventMan.h
 *
 *  Created on: 19 août 2020
 *      Author: r.schluep
 */

#ifndef BACKEND_EVENTMAN_H_
#define BACKEND_EVENTMAN_H_

#include <stdint.h>

/** backend event type defintion **/
typedef enum
{
	EVENT_TYPE_none,          // should never be here
	EVENT_TYPE_power_loss,    // Power loss detected. Saving must be performed
	EVENT_TYPE_alarm_machine, // machine security line has been opened
	EVENT_TYPE_alarm_bar_feeder, // bar feeder security line has been opened
	EVENT_TYPE_alarm_air,
	EVENT_TYPE_alarm_modbus_com,
	EVENT_TYPE_machine_state_change,
	EVENT_TYPE_command_stop,
	EVENT_TYPE_machine_stopped, // Falling edge of the start machine has been detected
	EVENT_TYPE_machine_regular_stop,
	EVENT_TYPE_machine_started,      // The machine started
	EVENT_TYPE_machine_start_warmup, // a scheduled start is imminent
	EVENT_TYPE_command_start_diagram,
	EVENT_TYPE_loading_ready, // Bar feeder has loaded a new bar and is ready
	EVENT_TYPE_loading_start, // Bar feeder has loaded a new bar and is ready
	EVENT_TYPE_loading_end,   // Bar feeder has loaded a new bar and is ready
	EVENT_TYPE_bar_feeder_is_back, // Bar feeder is at its back position (used for auto. stop operation)
	EVENT_TYPE_carrousel_inc,    // An incrementation of the Carrousel is asked
	EVENT_TYPE_carrousel_sensor, // The carrousel sensor is triggered
	EVENT_TYPE_clam_open,
	EVENT_TYPE_clam_closed,
	EVENT_TYPE_max,
} Event_Type_e;

/** backend queue type definition **/
typedef struct
{
	Event_Type_e type;
	void *data;
} Event_Queue_t;

/**
 * event manager setup. Init the event task and the event queue
 * @return 0 if setup has succeed
 */
int32_t eventMan_setup(void);

/**
 * Give an event to the event manager
 * @param type must be in the Event_Type_e list
 * @param data user data, may be used for given type
 * @return 0 if queued correctly
 */
int32_t eventMan_sendEvent(Event_Type_e type, void *data);

#endif /* BACKEND_EVENTMAN_H_ */
