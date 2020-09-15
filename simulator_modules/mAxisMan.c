#include "mAxisMan.h"

/**
 * setup of tAxisManager
 * @return 0 if success, else error
 */
int32_t mAxisMan_setup(void)
{
	return 0;
}

/**
 * Axis constructor. Build the given axis with the given config
 * @param id the id of the axis
 * @param config a structure that holds the configuration
 * @return 0 if success
 */
int32_t mAxisMan_configure_axis(Axis_e id, Axis_Config_t *config)
{
	return 0;
}

/**
 * set axis modbus error callback
 * @param id axis id
 * @param com_lost_cb callback called when modbus communication failed
 * @return 0 if success, else error
 */
int32_t mAxisMan_set_com_error_cb(Axis_e id, void (*com_lost_cb)(void *handler))
{
	return 0;
}

/** This function ask the axis manager to check if an axis is present and
 * configure the alarm depending of the presence of the motor
 */
int32_t mAxisMan_discover_axis(Axis_e id)
{
	return 0;
}

/**
 * Enable or disable the alarm on a drive. The goal is, when no motor is
 * present, to disable the emergency stop signal.
 * @param axis the axis id
 * @param state 1 to enable the alarm (motor is present), 0 to disable it
 * @return 0 if success, else error
 */
int32_t mAxisMan_set_alarm(Axis_e id, bool state)
{
	return 0;
}

/** change the speed of the specified axis to the given speed
 * this function first checks if the acceleration of the axis is set
 * to the value set in the parameters and sets it to that if not
 * then the axis is accelerated until it reaches that speed. No checks
 * are made to make sure the speed is reached before another order is
 * given
 **/
int32_t mAxisMan_set_speed(Axis_e id, int32_t speed_centi)
{
	return 0;
}

int32_t mAxisMan_set_acceleration(Axis_e id, int32_t acceleration)
{
	return 0;
}
int32_t mAxisMan_set_base_acceleration(Axis_e id)
{
	return 0;
}

/** change the speed of an axis constantly accelerating from a start
 * speed to an end speed. If the current speed is not equal to the start
 * speed it first performs mAxis_set_speed to reach said speed.
 * Calculations are done based on the current camshaft speed and are not
 * affected by any changes in the future. The time needed to reach the
 * start_speed is neglected in all Calculations
 */
int32_t mAxisMan_accelerate(Axis_e id, int32_t start_speed_centi,
                            int32_t end_speed_centi,
                            int32_t angle_interval_size)
{
	return 0;
}

/** stop an axis, there are three ways, either a simple stop
 * meaning the motor is free afterwards, a maintained stop, hence the
 * motor is not free to move and stays at the stop position. Finally the
 * maintained stop at a certain position. **/
int32_t mAxisMan_stop_free(Axis_e id)
{
	return 0;
}
int32_t mAxisMan_stop_maintained(Axis_e id)
{
	return 0;
}
int32_t mAxisMan_stop_maintained_at(Axis_e id, int32_t angle_abs_centi)
{
	return 0;
}
/* an axis can be turned on again by using mAxis_set_speed or
 * mAxis_accelerate
 */

/** rotate a stopped axis, if the axis is not stopped returns an error*/
int32_t mAxisMan_nombrage(Axis_e id, int32_t angle_rel_centi)
{
	return 0;
}
int32_t mAxisMan_nombrage_to(Axis_e id, int32_t angle_abs_centi)
{
	return 0;
}

/** set max torque of a motor **/
int32_t mAxisMan_set_max_torque(Axis_e id, int32_t torque_centi)
{
	return 0;
}
/** reset the max torque to the value set in the parameters */
int32_t mAxisMan_reset_max_torque(Axis_e id)
{
	return 0;
}

/** get alarm info */
int32_t mAxisMan_get_alarm_info(Axis_e id)
{
	return 0;
}