ENTRY(_start)

SECTIONS {
    . = 0x20000000;  /* Start address */

    .text : {
        *(.text)
    }
    
    .bss : {
        *(.bss)
    }

    /* Ensure the end of the sections */
    . = ALIGN(4);
}