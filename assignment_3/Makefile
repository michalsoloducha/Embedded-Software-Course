#*****************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#-----------------------------------------------------------------------------
# Build system based on GNU make, GNU tools and GCC.
#
# Use: make [TARGET]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      nm - Use GNU nm tool to list symbols from object files
#      build - Builds and links all source files
#      out-dump - Generates assembly OUT of the final OUT executable
#      clean - removes all generated files
#
# Author: Michal Soloducha
# Date: 2020-02-25
#
#-----------------------------------------------------------------------------

include sources.mk

# OUT name
OUT = c1m3

# Architecture Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
ABI = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs
	
# Compiler Flags and Defines
CC = arm-none-eabi-gcc
DUMP = arm-none-eabi-objdump
LDFLAGS = -Wl,-Map=$(OUT).map -T $(LINKER_FILE)
CFLAGS = $(INCLUDES) -Wall -Werror -g -O0 -std=c99 -DMSP432 -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=$(ABI) -mfpu=$(FPU) --specs=$(SPECS)

OBJECT_FILES = $(SOURCES:.c=.o)


# Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.
%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

# Use GNU nm tool to list symbols from object files
.PHONY: nm
nm: $(OBJECT_FILES)
	nm -f sysv $(OBJECT_FILES) > $(OUT).symb

# Compile all object files and link into a final executable.
.PHONY: build
build: $(OUT).out
$(OUT).out: $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) $(CFLAGS) $(LDFLAGS) -o $@

# Generate assembly OUT of the final OUT executable.
.PHONY: out-dump
out-dump: $(OUT).out
	$(DUMP) -d $< > $(OUT).dump

# Remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build OUT files.
.PHONY: clean
clean:
	rm -f $(OBJECT_FILES) $(OUT).map $(OUT).out $(OUT).symb $(OUT).dump
