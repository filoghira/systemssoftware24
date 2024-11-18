#ifndef SERIAL_DRIVER_H
#define SERIAL_DRIVER_H

#include <stdint.h>

// Function prototypes for the serial driver
void send_char(char c);
char receive_char();
void my_printf(const char *format, ...);

#endif // SERIAL_DRIVER_H
