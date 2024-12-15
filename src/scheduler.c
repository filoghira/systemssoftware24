#include "threads.h"
#include <stddef.h>

Thread *ready_queue = NULL;

// Initialize the scheduler (sets up necessary data structures, like the ready queue)
void scheduler_init() {
    // In this simple example, there's no complex initialization
    threads_init();  // Ensure threads are initialized
}

// Schedule the next thread to run (for simplicity, we pick the first one in the queue)
void schedule() {
    if (ready_queue == NULL) {
        return;  // No threads to schedule
    }

    Thread *current_thread = ready_queue;
    ready_queue = ready_queue->next;

    // Simulate thread execution (just run the function)
    current_thread->function(current_thread->arg);

    // After the thread finishes, we could either terminate it or re-add it to the queue
    terminate_thread();
}