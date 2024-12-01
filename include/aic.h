#ifndef AIC_H
#define AIC_H

#include <stdint.h>

// Base address for AIC (platform-specific, example value)
#define AIC_BASE ((volatile AIC_t *)0xFFFFF000)

// AIC Registers (example structure)
typedef struct {
    uint32_t AIC_SMR[32];  // Source Mode Register
    uint32_t AIC_SVR[32];  // Source Vector Register
    uint32_t AIC_IVR;      // IRQ Vector Register
    uint32_t AIC_FVR;      // FIQ Vector Register
    uint32_t AIC_ISR;      // Interrupt Status Register
    uint32_t AIC_IPR;      // Interrupt Pending Register
    uint32_t AIC_IMR;      // Interrupt Mask Register
    uint32_t AIC_CISR;     // Core Interrupt Status Register
    uint32_t Reserved1[2];
    uint32_t AIC_IECR;     // Interrupt Enable Command Register
    uint32_t AIC_IDCR;     // Interrupt Disable Command Register
    uint32_t AIC_ICCR;     // Interrupt Clear Command Register
    uint32_t AIC_ISCR;     // Interrupt Set Command Register
    uint32_t AIC_EOICR;    // End of Interrupt Command Register
    uint32_t AIC_SPU;      // Spurious Vector Register
    uint32_t Reserved2[37];
    uint32_t AIC_DCR;      // Debug Control Register
    uint32_t Reserved3[1];
    uint32_t AIC_FFER;     // Fast Forcing Enable Register
    uint32_t AIC_FFDR;     // Fast Forcing Disable Register
    uint32_t AIC_FFSR;     // Fast Forcing Status Register
} AIC_t;

// Function prototypes
void configure_interrupt(uint32_t irq_id, void (*handler)());

#endif // AIC_H
