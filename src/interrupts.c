#include "interrupts.h"
#include "threads.h"
#include "serial_driver.h"
#include "utils.h"

void enable_interrupts() {
    __asm__ volatile ("cpsie i");  // Enable IRQ interrupts (CPSIE i)
}

void process_character_thread(void *arg) {
    char c = *(char *)arg;  // Retrieve the character from the argument
    for (int i = 0; i < 10; i++) {
        my_printf("%c", c);
        delay(100);
    }
    terminate_thread();
}

void dbgu_handler(void) {
    if (DBGU_BASE->DBGU_SR & (1 << 0)) {  // Check if a character is available
        char c = DBGU_BASE->DBGU_RHR;     // Read the received character
        create_thread(process_character_thread, &c);  // Pass the function pointer and the argument
    }
}
