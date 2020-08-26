/*
 * xSignal.c
 *
 * @brief This is a tool to compute boolean signal and
 *        get all the possible values from it. That means
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
 *
 *  Created on: 26 sept. 2019
 *      Author: r.schluep
 */

#include <xSignal.h>

// Please always define TRUE and FALSE depending on your system and compiler
#define TRUE 	(1)
#define FALSE 	(0)


/**
 * @brief set the start values of the structure. Update only
 *        value and clk with aVal. The other flags are set
 *        to 0.
 *
 * @param xSignal reference to the xSignal structure to update
 * @param aVal input value at start of the program
 */
void XSignal_setDefaultValue(XSignal_t * xSignal, uint8_t aVal)
{
	xSignal->value = aVal;
	xSignal->clk = aVal;
	xSignal->rTrig = 0;
	xSignal->fTrig = 0;
	xSignal->toggled = 0;
}

/**
 * @brief update the xSignal structure with the given signal state
 *
 * @param xSignal reference to the xSignal structure to update
 * @param signal the associated signal
 */
void XSignal_update(XSignal_t * xSignal, uint8_t signal)
{
	xSignal->value = (0 != signal) ? 1 : 0;

	if(xSignal->value){
		if( !(xSignal->clk)){
			xSignal->rTrig = TRUE;
			xSignal->toggled ^= TRUE;
		}
		else{
			xSignal->rTrig = FALSE;
		}
		xSignal->clk = TRUE;
		xSignal->fTrig = FALSE;
	}
	//Si on est plus sur le bouton
	else{
		if( xSignal->clk){
			xSignal->fTrig = TRUE;
		}
		else{
			xSignal->fTrig = FALSE;
		}
		xSignal->clk = FALSE;
		xSignal->rTrig = FALSE;
	}
}


