/* kernel.lds: Linker script for ARM-based project */

ENTRY(_start) /* Entry point of the program */

/* Define memory regions */
MEMORY {
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K   /* ROM/Flash memory */
    RAM   (rwx) : ORIGIN = 0x08000000, LENGTH = 64K   /* RAM memory */
}

SECTIONS {
    .stack_undefined (NOLOAD) :
    {
        stack_undefined_top = . + 256;  /* Stack size for Undefined Mode */
        stack_undefined_base = .;
    } > RAM

    .stack_abort (NOLOAD) :
    {
        stack_abort_top = . + 256;     /* Stack size for Abort Mode */
        stack_abort_base = .;
    } > RAM
}