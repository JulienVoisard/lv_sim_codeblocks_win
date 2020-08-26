
#include "eventMan.h"

int32_t eventMan_setup(void)
{
}

/**
 * Give an event to the event manager
 * @param type must be in the Event_Type_e list
 * @param data user data, may be used for given type
 * @return 0 if queued correctly
 */
int32_t eventMan_sendEvent(Event_Type_e type, void *data)
{
}