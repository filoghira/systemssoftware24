#ifndef THREADS_H
#define THREADS_H

#include <stdint.h>

#define MAX_THREADS 16
#define STACK_SIZE 1024  // Stack size per thread

typedef struct Thread {
    void (*function)(void*);  // Function to be executed by the thread
    void *arg;                // Argument to be passed to the thread function
    struct Thread *next;      // Next thread in the queue
} Thread;

// Functions
void threads_init();
// In threads.h
Thread *create_thread(void (*thread_func)(void *), void *arg);
void terminate_thread();

#endif // THREADS_H
