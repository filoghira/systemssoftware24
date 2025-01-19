#include "exception_handlers.h"
#include "serial_driver.h"
#include "scheduler.h"
#include "threads.h"
#include "timer.h"
#include "interrupts.h"

extern void sys_print_char(char c);
extern char sys_read_char(void);
extern void sys_create_thread(void (*function)(void *), void *arg);
extern void sys_terminate_thread(void);
extern void sys_delay(int milliseconds);

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

void swi_handler(void) {
    int swi_number;
    
    // Get the SWI number from register R7 (standard for SWI instruction in ARM)
    asm volatile("mov %0, r7" : "=r"(swi_number));

    switch (swi_number) {
        case 0: { // sys_print_char
            char c;
            asm volatile("mov %0, r0" : "=r"(c)); // Get char to print from r0
            sys_print_char(c);
            break;
        }
        case 1: { // sys_read_char
            char c = sys_read_char();
            asm volatile("mov r0, %0" : : "r"(c)); // Return char to r0
            break;
        }
        case 2: { // sys_create_thread
            void (*function)(void *);
            void *arg;
            asm volatile("mov %0, r0" : "=r"(function)); // Get function pointer from r0
            asm volatile("mov %0, r1" : "=r"(arg));     // Get argument from r1
            sys_create_thread(function, arg);
            break;
        }
        case 3: { // sys_terminate_thread
            sys_terminate_thread();
            break;
        }
        case 4: { // sys_delay
            int milliseconds;
            asm volatile("mov %0, r0" : "=r"(milliseconds)); // Get delay time from r0
            sys_delay(milliseconds);
            break;
        }
        default:
            // Handle invalid system call
            break;
    }
}