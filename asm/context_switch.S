.global context_switch_asm
context_switch_asm:
    // Save current thread context
    stmfd r0!, {r4-r11, lr}  // Save callee-saved registers and LR
    str sp, [r0]             // Save SP to current thread's stack_ptr

    // Load next thread context
    ldr sp, [r1]             // Load SP from next thread's stack_ptr
    ldmfd sp!, {r4-r11, lr}  // Restore callee-saved registers and LR
    bx lr                    // Return to the next thread
