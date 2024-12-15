#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "threads.h"

extern Thread *ready_queue;

extern void scheduler_init();
extern void schedule();

#endif // SCHEDULER_H
