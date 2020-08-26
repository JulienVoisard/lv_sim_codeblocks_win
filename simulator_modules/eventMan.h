/*
 * eventMan.h
 *
 *  Created on: 19 aoรปt 2020
 *      Author: r.schluep
 */

#ifndef BACKEND_EVENTMAN_H_
#define BACKEND_EVENTMAN_H_

#include <stdint.h>

/** This has to be a copy of the same file in backend **/
typedef enum
{
	EVENT_TYPE_none,          // should never be here
	EVENT_TYPE_power_loss,    // Power loss detected. Saving must be performed
	EVENT_TYPE_alarm_machine, // machine security line has been opened
	EVENT_TYPE_alarm_bar_feeder, // bar feeder security line has been opened
	EVENT_TYPE_alarm_air,        // Air pressure not enough detected
	EVENT_TYPE_start_machine,    // A start machine has been asked
	EVENT_TYPE_stop_machine, // Falling edge of the start machine has been detected
	EVENT_TYPE_ready_for_loading, // Bar feeder want to load
	EVENT_TYPE_end_of_loading, // Bar feeder has loaded a new bar and is ready
	EVENT_TYPE_ct_input_rising, // CT inputs have rised. See documentation for more info. TODO
	EVENT_TYPE_ct_input_falling, // CT inputs have falled. See documentation for more info. TODO
	EVENT_TYPE_lever_engaged,    // Going to manual operation
	EVENT_TYPE_lever_desengaged, // Going to automatic operation
	EVENT_TYPE_spindle_speed, // The spindle speed is computed and ready to be used
	EVENT_TYPE_bar_feeder_auto, // Bar feeder is going into automatic operation
	EVENT_TYPE_bar_feeder_manual, // Bar feeder is stopped
	EVENT_TYPE_bar_feeder_is_back, // Bar feeder is at its back position (used for auto. stop operation)
	EVENT_TYPE_carrousel_inc,    // An incrementation of the Carrousel is asked
	EVENT_TYPE_carrousel_sensor, // The carrousel sensor is triggered
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
