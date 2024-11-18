#ifndef EXCEPTION_HANDLERS_H
#define EXCEPTION_HANDLERS_H

// Function prototypes for the exception handlers
void undefined_instruction_handler();
void software_interrupt_handler();
void data_abort_handler();
void prefetch_abort_handler();
void reserved();
void irq_handler();
void fiq_handler();

#endif
