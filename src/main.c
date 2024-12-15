#include "serial_driver.h"
#include "timer.h"
#include "utils.h"
#include "interrupts.h"
#include "threads.h"
#include "scheduler.h"
#include <stdlib.h>

void main_thread() {
    while (1) {
        my_printf("Main thread is running\n");
        delay(500);
    }
}

void secondary_thread() {
    for (int i = 0; i < 10; i++) {
        my_printf("Secondary thread: iteration %d\n", i);
        delay(100);
    }
    terminate_thread();
}

void test_application() {
    while (1) {
        my_printf("Press a key: ");
        char c = receive_char();  // Wait for input
        my_printf("\nReceived: %c\n", c);

        for (int i = 0; i < 20; i++) {
            my_printf("%c", c);  // Simulate computation
            delay(100);          // Small delay
        }
        my_printf("\n");
    }
}

int main() {
    threads_init();
    scheduler_init();
    init_system_timer(10);  // Configure a timer interrupt every 100ms
    enable_interrupts();

    create_thread(main_thread, NULL);      // If no argument is needed
    create_thread(secondary_thread, NULL); // If no argument is needed


    while (1) {
        // Idle loop
    }

    return 0;
}