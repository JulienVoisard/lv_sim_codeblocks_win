#include "mTaskDef.h"
#include "FreeRTOS.h"
#include "task.h"
#include "eventMan.h"
#include "machine.h"
#include "machine_communication.h"
#include "diagram_execution.h"
#include "mTime.h"


static void eventMan_update(void *vParam)
{
	(void)(vParam);
	Event_Queue_t mess;

	// setup all backend module



		// update of all backend element
		machine_communication_update();
		diagram_execution_update();
		machine_update();
}

int32_t eventMan_setup(void)
{
    machine_communication_setup();
	machine_setup();
    	lv_task_create(eventMan_update, 10, TASK_EVENT_MAN_PRIORITY, NULL);

	return 0;

}

/**
 * Give an event to the event manager
 * @param type must be in the Event_Type_e list
 * @param data user data, may be used for given type
 * @return 0 if queued correctly
 */
int32_t eventMan_sendEvent(Event_Type_e type, void *data)
{
	return 1;
}




