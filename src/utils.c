#include "utils.h"

void delay(int milliseconds) {
    volatile int count = milliseconds * 1000; // Adjust based on system clock
    while (count--) {
        __asm__ volatile ("nop");  // Prevent compiler optimization
    }
}
