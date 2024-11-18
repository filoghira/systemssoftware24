/* start.S */
.section .text
.global _start
.global reset_handler

/* Entry Point */
_start:
    b reset_handler         /* Branch to Reset Handler */

/* Interrupt Vector Table */
.section .vector_table, "a" /* Place IVT in its own section */
.align 4
vector_table:
    b reset_handler                /* Reset */
    b undefined_instruction_handler /* Undefined Instruction */
    b software_interrupt_handler   /* Software Interrupt (SWI) */
    b prefetch_abort_handler       /* Prefetch Abort */
    b data_abort_handler           /* Data Abort */
    b reserved                     /* Reserved */
    b irq_handler                  /* IRQ */
    b fiq_handler                  /* FIQ */

/* Reset Handler */
reset_handler:
    /* Disable interrupts */
    cpsid i

    /* Set up stacks for each mode */
    ldr sp, =stack_top              /* Supervisor mode stack */
    msr CPSR_c, #0x1B              /* Switch to Undefined mode */
    ldr sp, =stack_undefined_top
    msr CPSR_c, #0x17              /* Switch to Abort mode */
    ldr sp, =stack_abort_top
    msr CPSR_c, #0x13              /* Back to Supervisor mode */

    /* Perform memory remap (optional) */
    bl remap_memory

    /* Call the C main function */
    bl main

halt_system:
    /* Halt the system in an infinite loop */
    b halt_system

/* Define Stack Memory */
.section .bss
.align 4
stack:
    .space 1024    /* Stack size for Supervisor mode */
stack_top:
stack_undefined:
    .space 256     /* Stack size for Undefined mode */
stack_undefined_top:
stack_abort:
    .space 256     /* Stack size for Abort mode */
stack_abort_top: