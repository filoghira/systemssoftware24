#include "threads.h"
#include <stddef.h>

Thread *ready_queue = NULL;

// Initialize the scheduler (sets up necessary data structures, like the ready queue)
void scheduler_init() {
    // In this simple example, there's no complex initialization
    threads_init();  // Ensure threads are initialized
}

void add_to_ready_queue(Thread *t) {
    if (ready_queue == NULL) {
        ready_queue = t;
    } else {
        Thread *current = ready_queue;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = t;
    }
}

void schedule() {
    if (ready_queue == NULL) {
        return;  // No threads to schedule
    }

    Thread *current_thread = ready_queue;
    ready_queue = ready_queue->next;

    // If thread is blocked, don't run it immediately
    if (current_thread->blocked) {
        // Keep the thread in the queue and re-check it next time
        add_to_ready_queue(current_thread);
        return;
    }

    // Simulate thread execution (just run the function)
    current_thread->function(current_thread->arg);

    // After the thread finishes, terminate it or re-add it to the queue
    terminate_thread();
}