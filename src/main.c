#include "serial_driver.h"
#include "timer.h"
#include "utils.h"
#include "interrupts.h"

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
    init_system_timer(1);       // 1Hz timer interrupts
    init_dbg_interrupts();      // Enable DBGU interrupts
    enable_interrupts();        // Enable global IRQs
    test_application();         // Run the application
    return 0;
}