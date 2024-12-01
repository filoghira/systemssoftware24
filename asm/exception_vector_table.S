.section .vector_table, "a"
vector_table:
    b reset_handler               /* Reset */
    b undefined_instruction_handler /* Undefined Instruction */
    b software_interrupt_handler  /* SWI */
    b prefetch_abort_handler      /* Prefetch Abort */
    b data_abort_handler          /* Data Abort */
    b reserved                    /* Reserved */
    b irq_handler                 /* IRQ */
    b fiq_handler                 /* FIQ */
irq_handler:
    ldr pc, =system_timer_handler /* Branch to timer or other IRQ handler */
