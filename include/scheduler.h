#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "threads.h"

extern Thread *ready_queue;

extern void scheduler_init();

// Function to schedule the next thread to run
void schedule(void);

// Functions to manage the ready queue
void add_to_ready_queue(Thread *thread);
void remove_from_ready_queue(Thread *thread);

#endif // SCHEDULER_H
