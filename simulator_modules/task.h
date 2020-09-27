#ifndef TASK_H
#define TASK_H

#include "stdint.h"
#include "time.h"


#define pdMS_TO_TICKS(ms) (CLOCKS_PER_SEC * ms / 1000)
#define pdTICKS_TO_MS(ticks) (ticks *1000 /CLOCKS_PER_SEC)

int64_t xTaskGetTickCount();
#endif
