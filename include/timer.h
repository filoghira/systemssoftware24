#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

// Base address for the System Timer (platform-specific, example value)
#define ST_BASE ((volatile SystemTimer_t *)0xFFFFFD30)

// System Timer Registers (example structure for PIT)
typedef struct {
    uint32_t PITC_PIMR;  // Periodic Interval Mode Register
    uint32_t PITC_PISR;  // Periodic Interval Status Register
    uint32_t PITC_PIVR;  // Periodic Interval Value Register
    uint32_t PITC_PIIR;  // Periodic Interval Image Register
} SystemTimer_t;

// System Timer IRQ number (platform-specific, example value)
#define SYSTEM_TIMER_IRQ 1

// Function prototypes
void init_system_timer(uint32_t frequency_hz);
void system_timer_handler();

// System call to delay a thread for a given time in milliseconds
void sys_delay(int milliseconds);

// Delay function for active waiting (e.g., busy-waiting)
void delay(int milliseconds);

#endif // TIMER_H
