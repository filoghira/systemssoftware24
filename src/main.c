#include "serial_driver.h"
#include "memory_map.h"

int main() {
    memory_remap();  // Map writable memory for the IVT

    while (1) {
        my_printf("Choose an exception to trigger:\n");
        my_printf("1. Undefined Instruction\n2. Data Abort\n3. Software Interrupt\n");

        char choice = receive_char();

        switch (choice) {
            case '1':
                asm volatile (".word 0xE7F000F0");  // Trigger Undefined Instruction
                break;
            case '2':
                *(volatile int *)0xDEADBEEF = 42;  // Trigger Data Abort
                break;
            case '3':
                asm volatile ("swi 0");  // Trigger SWI
                break;
            default:
                my_printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}
