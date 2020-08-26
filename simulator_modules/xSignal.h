/*
 * xSignal.h
 *
 * @brief This is a tool to compute boolean signal and
 *        get all the possible values from. That means
 *        you create a xSignal var, update it with a
 *        digital input, and then access to the rising
 *        and falling edges, toggle state and so on ...
 *
 *        Use it like this:
 *
 *        // in initialization phase (before the while (1)
 *        // of the task
 *        XSignal_t input1_x;
 *        // set the default start value. Maybe you should
 *        // do an physical input read, then affect the
 *        // structre with what you have readed :)
 *        XSignal_setDefaultValue(&input1_x, 0);
 *
 *        // In the infinite loop of the task, do this
 *        XSignal_update(&input1_x, myRealInputSignalBoolean);
 *
 *        // use the RTrig signal
 *        if(input1_x.RTrig)
 *        {
 *          // do something
 *        }
 *  Created on: 26 sept. 2019
 *      Author: r.schluep
 */

#ifndef XSIGNAL_H_
#define XSIGNAL_H_

#include <stdint.h>

typedef struct{
	uint8_t value   : 1;
	uint8_t rTrig   : 1;
	uint8_t fTrig   : 1;
	uint8_t clk     : 1;
	uint8_t toggled : 1;
}XSignal_t;

/**
 * @brief set the start values of the structure. Update only
 *        value and clk with aVal. The other flags are set
 *        to 0.
 *
 * @param xSignal reference to the xSignal structure to update
 * @param aVal input value at start of the program
 */
void XSignal_setDefaultValue(XSignal_t * xSignal, uint8_t aVal);
/**
 * @brief update the xSignal structure with the given signal state
 *
 * @param xSignal reference to the xSignal structure to update
 * @param signal the associated signal
 */
void XSignal_update(XSignal_t * xSignal, uint8_t signal);

#endif /* XSIGNAL_H_ */
