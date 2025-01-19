#ifndef THREADS_H
#define THREADS_H

#include <stdint.h>

#define MAX_THREADS 16
#define STACK_SIZE 1024  // Stack size per thread

typedef struct Thread {
    void (*function)(void*);  // Function to be executed by the thread
    void *arg;                // Argument to be passed to the thread function
    struct Thread *next;      // Next thread in the queue
    int blocked;
} Thread;

// Function to create a thread
void sys_create_thread(void (*function)(void *), void *arg);

// Function to terminate a thread
void sys_terminate_thread(void);

// Additional thread management functions
Thread* create_thread(void (*function)(void *), void *arg);
void terminate_thread(void);
void threads_init(void);

#endif // THREADS_H
