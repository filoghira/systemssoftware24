#ifndef SERIAL_DRIVER_H
#define SERIAL_DRIVER_H

#include <stdint.h>

// Base address for DBGU (platform-specific)
#define DBGU_BASE ((volatile DBGU_t *)0xFFFFF200)

// DBGU Registers (structure example)
typedef struct {
    uint32_t DBGU_CR;    // Control Register
    uint32_t DBGU_MR;    // Mode Register
    uint32_t DBGU_IER;   // Interrupt Enable Register
    uint32_t DBGU_IDR;   // Interrupt Disable Register
    uint32_t DBGU_IMR;   // Interrupt Mask Register
    uint32_t DBGU_SR;    // Status Register
    uint32_t DBGU_RHR;   // Receive Holding Register
    uint32_t DBGU_THR;   // Transmit Holding Register
    uint32_t DBGU_BRGR;  // Baud Rate Generator Register
    uint32_t Reserved[7];
    uint32_t DBGU_CIDR;  // Chip ID Register
    uint32_t DBGU_EXID;  // Chip ID Extension Register
    uint32_t DBGU_FNTR;  // Force NTRST Register
} DBGU_t;

// DBGU IRQ number (example)
#define DBGU_IRQ 2

// Function prototypes
void init_dbg_interrupts();
void send_char(char c);
char receive_char();
void my_printf(const char *format, ...);

#endif // SERIAL_DRIVER_H
