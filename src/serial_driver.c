#include <stdarg.h>
#include <stdint.h>

// UART base address for VersatilePB
#define UART_BASE      0x9000000
#define THR            (*(volatile uint32_t *)(UART_BASE + 0x00))  // Transmitter Holding Register
#define RHR            (*(volatile uint32_t *)(UART_BASE + 0x04))  // Receiver Holding Register
#define FR             (*(volatile uint32_t *)(UART_BASE + 0x18))  // Flag Register

// Status flags
#define THR_READY      (1 << 5)  // Transmitter Holding Register is ready
#define RHR_READY      (1 << 0)  // Receiver Holding Register has data

// Send a character over the serial interface
void send_char(char c) {
    while (FR & THR_READY);  // Wait until the THR is ready
    THR = c;  // Write character to the THR
}

// Receive a character from the serial interface
char receive_char() {
    while (FR & RHR_READY);  // Wait until there is data in the RHR
    return RHR;  // Read character from the RHR
}

// Helper function to convert an integer to hexadecimal string
void int_to_hex(unsigned int num, char *buffer) {
    const char *hex_digits = "0123456789ABCDEF";
    for (int i = 7; i >= 0; i--) {
        buffer[i] = hex_digits[num & 0xF];  // Get the last hex digit
        num >>= 4;  // Shift right by 4 bits to process the next hex digit
    }
    buffer[8] = '\0';  // Null-terminate the string
}

// Basic printf-like function with support for %c, %s, %x, %p
void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    while (*format) {
        if (*format == '%' && *(format + 1)) {
            format++;
            switch (*format) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    send_char(c);
                    break;
                }
                case 's': {
                    const char *s = va_arg(args, const char *);
                    while (*s) send_char(*s++);
                    break;
                }
                case 'x': {
                    unsigned int num = va_arg(args, unsigned int);
                    char hex_buffer[9];
                    int_to_hex(num, hex_buffer);
                    for (int i = 0; hex_buffer[i] != '\0'; i++) {
                        send_char(hex_buffer[i]);
                    }
                    break;
                }
                case 'p': {
                    void *ptr = va_arg(args, void *);
                    unsigned int addr = (uintptr_t)ptr;
                    char hex_buffer[11];  // Enough for "0x" + 8 hex digits + '\0'
                    hex_buffer[0] = '0';
                    hex_buffer[1] = 'x';
                    int_to_hex(addr, hex_buffer + 2);  // Pass the correct buffer size
                    for (int i = 0; hex_buffer[i] != '\0'; i++) {
                        send_char(hex_buffer[i]);
                    }
                    break;
                }
                default:
                    send_char('%');
                    send_char(*format);
                    break;
            }
        } else {
            send_char(*format);
        }
        format++;
    }
    
    va_end(args);
}
