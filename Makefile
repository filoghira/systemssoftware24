# Project Name
TARGET = kernel.elf

# Toolchain and Flags
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -O0 -g -Wall -nostdlib -nostartfiles
LDFLAGS = -T kernel.lds

# Source Files
SRC_C = src/main.c src/serial_driver.c src/exception_handlers.c src/memory_map.c
SRC_ASM = asm/start.S asm/exception_vector_table.S asm/stack_init.S

# Include Directories
INCLUDES = -Iinclude

# Build Directory
BUILD_DIR = build

# Final Executable
OUTPUT = $(BUILD_DIR)/$(TARGET)

# Default Target: Build the Project
all: $(OUTPUT)

# Linking Stage
$(OUTPUT): $(SRC_C) $(SRC_ASM) kernel.lds
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) $(SRC_C) $(SRC_ASM) -o $(OUTPUT)

# Run in QEMU
run: $(OUTPUT)
	qemu-system-arm -M versatilepb -nographic -kernel $(OUTPUT)

# Debug with QEMU and GDB
debug: $(OUTPUT)
	qemu-system-arm -M versatilepb -nographic -kernel $(OUTPUT) -S -gdb tcp::1234

# Clean Build Artifacts
clean:
	rm -rf $(BUILD_DIR)
