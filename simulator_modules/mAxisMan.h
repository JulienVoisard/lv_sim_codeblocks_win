/**
 * tAxisMan.h
 *
 * Axis manager layer. This layer
 *   - create and delete new axis
 *   - give an abstraction of several drive mechanism
 *   - update the status of each axis
 *   - schedule axis operations (include synchronized movement)
 *
 *  Created on: 30 juin 2020
 *      Author: r.schluep
 */

#ifndef MODBUS_TAXISMAN_H_
#define MODBUS_TAXISMAN_H_

#include "machine_definitions.h"
#include <stdbool.h>
#include <stdint.h>

/** Axis configuration type **/
typedef struct
{
	Axis_e drive_type;  ///< kind of modbus driver to use
	uint8_t axeAdresse; ///< modbus addresses of this axis
	int32_t conversion; ///< conversion in micro resolution
} Axis_Config_t;

/**
 * setup of tAxisManager
 * @return 0 if success, else error
 */
int32_t mAxisMan_setup(void);

/**
 * Axis constructor. Build the given axis with the given config
 * @param id the id of the axis
 * @param config a structure that holds the configuration
 * @return 0 if success
 */
int32_t mAxisMan_configure_axis(Axis_e id, Axis_Config_t *config);

/**
 * set axis modbus error callback
 * @param id axis id
 * @param com_lost_cb callback called when modbus communication failed
 * @return 0 if success, else error
 */
int32_t mAxisMan_set_com_error_cb(Axis_e id,
                                  void (*com_lost_cb)(void *handler));

/** This function ask the axis manager to check if an axis is present and
 * configure the alarm depending of the presence of the motor
 */
int32_t mAxisMan_discover_axis(Axis_e id);

/**
 * Enable or disable the alarm on a drive. The goal is, when no motor is
 * present, to disable the emergency stop signal.
 * @param axis the axis id
 * @param state 1 to enable the alarm (motor is present), 0 to disable it
 * @return 0 if success, else error
 */
int32_t mAxisMan_set_alarm(Axis_e id, bool state);

/** change the speed of the specified axis to the given speed
 * this function first checks if the acceleration of the axis is set
 * to the value set in the parameters and sets it to that if not
 * then the axis is accelerated until it reaches that speed. No checks
 * are made to make sure the speed is reached before another order is
 * given
 **/
int32_t mAxisMan_set_speed(Axis_e id, int32_t speed_centi);

int32_t mAxisMan_set_acceleration(Axis_e id, int32_t acceleration);

int32_t mAxisMan_set_base_acceleration(Axis_e id);

/** change the speed of an axis constantly accelerating from a start
 * speed to an end speed. If the current speed is not equal to the start
 * speed it first performs mAxis_set_speed to reach said speed.
 * Calculations are done based on the current camshaft speed and are not
 * affected by any changes in the future. The time needed to reach the
 * start_speed is neglected in all Calculations
 */
int32_t mAxisMan_accelerate(Axis_e id, int32_t start_speed_centi,
                            int32_t end_speed_centi,
                            int32_t angle_interval_size);

/** stop an axis, there are three ways, either a simple stop
 * meaning the motor is free afterwards, a maintained stop, hence the
 * motor is not free to move and stays at the stop position. Finally the
 * maintained stop at a certain position. **/
int32_t mAxisMan_execution_stop(Axis_e id);
int32_t mAxisMan_stop_free(Axis_e id);
int32_t mAxisMan_stop_maintained(Axis_e id);
int32_t mAxisMan_stop_angle_abs(Axis_e id, int32_t angle_centi);
int32_t mAxisMan_pos_angle_abs(Axis_e id, int32_t angle_centi);
int32_t mAxisMan_pos_angle_rel(Axis_e id, int32_t angle_centi);
int32_t mAxisMan_pos_linear_abs(Axis_e id, int32_t pos_micro);
int32_t mAxisMan_pos_linear_rel(Axis_e id, int32_t pos_micro);

/** set max torque of a motor **/
int32_t mAxisMan_set_max_torque(Axis_e id, int32_t torque_centi);
/** reset the max torque to the value set in the parameters */
int32_t mAxisMan_reset_max_torque(Axis_e id);

/** get alarm info */
int32_t mAxisMan_get_alarm_info(Axis_e id);

#endif /* MODBUS_TAXISMAN_H_ */
