#include "aic.h"

void configure_interrupt(uint32_t irq_id, void (*handler)()) {
    AIC_BASE->AIC_IDCR = (1 << irq_id);  // Disable interrupt during setup
    AIC_BASE->AIC_SVR[irq_id] = (uint32_t)handler; // Set handler address
    AIC_BASE->AIC_ICCR = (1 << irq_id);  // Clear pending interrupts
    AIC_BASE->AIC_IECR = (1 << irq_id);  // Enable interrupt
}