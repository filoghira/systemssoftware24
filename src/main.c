#include "serial_driver.h"  // Include the header for serial functions
#include "threads.h"         // Include the thread functions (you'll need to define them)
#include "scheduler.h"       // Include the scheduler (you'll need to implement it)
#include "utils.h"           // Include utility functions (like delay)
#include "timer.h"

void thread_function(void *arg) {
    char received_char = *(char *)arg;

    // Print the character repeatedly with pauses
    for (int i = 0; i < 10; i++) {
        sys_print_char(received_char);  // Print the received character using system call
        delay(500);                     // Wait for a while
    }
}


int main(void) {
    char c;

    // Initialize the system (serial driver, scheduler, etc.)
    init_system_timer(1000);  // Example timer initialization (adjust frequency as needed)

    // Main loop: Wait for a character and create a thread to handle it
    while (1) {
        c = sys_read_char();  // Wait for a character from the user
        sys_print_char(c);    // Echo the character

        // Create a new thread to handle the received character
        create_thread(thread_function, (void *)(&c));  // Pass the character as argument to the thread
    }

    return 0;
}
