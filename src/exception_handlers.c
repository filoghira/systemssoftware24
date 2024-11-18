#include "exception_handlers.h"
#include "serial_driver.h"

void undefined_instruction_handler() {
    my_printf("Undefined instruction exception\n");

    // Disable interrupts by modifying the CPSR in ARM mode
    __asm__ volatile(
        "MRS     r0, cpsr        \n"
        "ORR     r0, r0, #0x80   \n"
        "MSR     cpsr_c, r0      \n"
    );

    while (1);
}

void software_interrupt_handler() {
    my_printf("Software interrupt exception\n");

    // Disable interrupts by modifying the CPSR in ARM mode
    __asm__ volatile(
        "MRS     r0, cpsr        \n"
        "ORR     r0, r0, #0x80   \n"
        "MSR     cpsr_c, r0      \n"
    );

    while (1);
}

void data_abort_handler() {
    my_printf("Data abort exception\n");

    // Disable interrupts by modifying the CPSR in ARM mode
    __asm__ volatile(
        "MRS     r0, cpsr        \n"
        "ORR     r0, r0, #0x80   \n"
        "MSR     cpsr_c, r0      \n"
    );

    while (1);
}

void prefetch_abort_handler() {
    my_printf("Prefetch abort exception\n");

    // Disable interrupts by modifying the CPSR in ARM mode
    __asm__ volatile(
        "MRS     r0, cpsr        \n"
        "ORR     r0, r0, #0x80   \n"
        "MSR     cpsr_c, r0      \n"
    );

    while (1);
}

void reserved() {
    while (1);
}

void irq_handler() {
    while (1);
}

void fiq_handler() {
    while (1);
}
