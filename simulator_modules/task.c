#include "task.h"
#include <time.h>

int64_t xTaskGetTickCount()
{
	return clock();
}