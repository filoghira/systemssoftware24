.global setup_stacks
setup_stacks:
    ldr sp, =stack_undefined_top  /* Undefined Mode Stack */
    msr CPSR_c, #0x1B            /* Switch to Abort Mode */
    ldr sp, =stack_abort_top     /* Abort Mode Stack */
    msr CPSR_c, #0x13            /* Return to Supervisor Mode */
    bx lr                        /* Return to C code */
