#include <stddef.h>
#include "scheduler.h"

void threads_init(void) {
    ready_queue = NULL;
}

#define THREAD_POOL_SIZE 10
static uint8_t thread_pool[THREAD_POOL_SIZE * sizeof(Thread)];
static size_t pool_index = 0;

void *simple_malloc(size_t size) {
    if (pool_index + size <= sizeof(thread_pool)) {
        void *ptr = &thread_pool[pool_index];
        pool_index += size;
        return ptr;
    }
    return NULL;
}

void simple_free(void *ptr) {
    // Simple allocator, doesn't handle freeing individual blocks
}

Thread *create_thread(void (*function)(void *), void *arg) {
    Thread *new_thread = (Thread *)simple_malloc(sizeof(Thread));
    if (new_thread == NULL) {
        return NULL;
    }

    new_thread->function = function;
    new_thread->arg = arg;
    new_thread->next = NULL;

    return new_thread;
}

void terminate_thread(void) {
    if (ready_queue != NULL) {
        Thread *old_thread = ready_queue;
        ready_queue = ready_queue->next;
        simple_free(old_thread);  // Free resources
    }
}

// System call to create a thread
void sys_create_thread(void (*function)(void *), void *arg) {
    create_thread(function, arg);
}

// System call to terminate a thread
void sys_terminate_thread(void) {
    terminate_thread();
}
