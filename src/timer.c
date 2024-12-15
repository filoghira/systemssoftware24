#include "timer.h"
#include "aic.h"
#include "serial_driver.h"
#include "scheduler.h"
#include "threads.h"

void init_system_timer(uint32_t frequency_hz) {
    uint32_t timer_clock = 32768; // Typical clock for PIT
    uint32_t compare_value = timer_clock / frequency_hz;
    
    ST_BASE->PITC_PIMR = (compare_value & 0xFFFFF) | (1 << 24); // Enable PIT
    configure_interrupt(SYSTEM_TIMER_IRQ, system_timer_handler);
}

void system_timer_handler() {
    ST_BASE->PITC_PIVR;  // Clear timer interrupt
    my_printf("!\n");    // Print timer interrupt indicator
    schedule();          // Trigger the scheduler
}