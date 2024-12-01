#include "interrupts.h"

void enable_interrupts() {
    __asm__ volatile ("cpsie i");  // Enable IRQ interrupts (CPSIE i)
}
