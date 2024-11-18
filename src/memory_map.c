#include "memory_map.h"
#include "exception_handlers.h"

// Function to initialize memory mapping (IVT remapping)
void memory_remap() {
    // Assuming memory is already mapped at address 0x0
    // and IVT is located in a fixed region in ROM
    // The remap code will copy IVT into writable memory
    unsigned int *ivt = (unsigned int *) 0x10000000;  // New location in RAM
    unsigned int *ivt_orig = (unsigned int *) 0x00000000;  // Original IVT in ROM

    // Copy IVT entries
    for (int i = 0; i < 16; i++) {
        ivt[i] = ivt_orig[i];
    }
    
    // Install new handlers for exceptions
    ivt[0] = (unsigned int) undefined_instruction_handler;
    ivt[1] = (unsigned int) software_interrupt_handler;
    ivt[2] = (unsigned int) data_abort_handler;
    ivt[3] = (unsigned int) prefetch_abort_handler;
}
