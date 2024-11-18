#include "exception_handlers.h"
#include "serial_driver.h"

void undefined_instruction_handler() {
    // Print the error message
    my_printf("Undefined instruction exception\n");

    // Disable interrupts by modifying the CPSR in ARM mode
    __asm__ volatile(
        "MRS     r0, cpsr        \n"  // Load the CPSR into r0
        "ORR     r0, r0, #0x80   \n"  // Set the I bit (0x80) to disable interrupts
        "MSR     cpsr_c, r0      \n"  // Write the modified CPSR back to disable interrupts
    );

    // Halt system
    while (1);  // Infinite loop to halt system
}

void software_interrupt_handler() {
    // Print the error message
    my_printf("Software interrupt exception\n");

    // Disable interrupts by modifying the CPSR in ARM mode
    __asm__ volatile(
        "MRS     r0, cpsr        \n"  // Load the CPSR into r0
        "ORR     r0, r0, #0x80   \n"  // Set the I bit (0x80) to disable interrupts
        "MSR     cpsr_c, r0      \n"  // Write the modified CPSR back to disable interrupts
    );

    // Halt system
    while (1);  // Infinite loop to halt system
}

void data_abort_handler() {
    // Print the error message
    my_printf("Data abort exception\n");

    // Disable interrupts by modifying the CPSR in ARM mode
    __asm__ volatile(
        "MRS     r0, cpsr        \n"  // Load the CPSR into r0
        "ORR     r0, r0, #0x80   \n"  // Set the I bit (0x80) to disable interrupts
        "MSR     cpsr_c, r0      \n"  // Write the modified CPSR back to disable interrupts
    );

    // Halt system
    while (1);  // Infinite loop to halt system
}

void prefetch_abort_handler() {
    // This may not be used for now but could be reserved
    my_printf("Prefetch abort exception\n");

    // Disable interrupts by modifying the CPSR in ARM mode
    __asm__ volatile(
        "MRS     r0, cpsr        \n"  // Load the CPSR into r0
        "ORR     r0, r0, #0x80   \n"  // Set the I bit (0x80) to disable interrupts
        "MSR     cpsr_c, r0      \n"  // Write the modified CPSR back to disable interrupts
    );

    // Halt system
    while (1);  // Infinite loop to halt system
}
