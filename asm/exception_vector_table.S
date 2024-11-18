.global _start
.global vectors

.section .vectors
vectors:
    b undefined_instruction_handler   // Undefined instruction
    b software_interrupt_handler      // Software interrupt
    b data_abort_handler             // Data abort
    b prefetch_abort_handler         // Prefetch abort (optional)
    .word 0                           // Reserved for the rest
    .word 0                           // Reserved for the rest
    .word 0                           // Reserved for the rest
    .word 0                           // Reserved for the rest

.section .text
_start:
    // Setup code for the ARM processor and memory remapping will go here
    // Additional setup may be required to map the IVT into RAM
    b main   // Jump to the main program
