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

#------------------------------------------------------------------------------
# Build system based on GNU tools, GCC and GNU make. It supports two 
# platforms: the host environment and the target embedded system MSP432.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i - Builds <FILE>.i preprocessed file
#      <FILE>.asm - Builds <FILE>.asm and final output assembly files
#      <FILE>.o - Builds <FILE>.o object file
#      compile-all - Builds all source files, but do not link
#      build - Builds and links all source files
#      clean - removes all generated files
#
# Platform Overrides:
#      HOST - host environment
#      MSP432 - target embedded system
#
#
# Author: Michal Soloducha
# Date: 2020-02-13
#
#------------------------------------------------------------------------------
include sources.mk

# output name
OUTPUT = c1m2

ifeq ($(PLATFORM),HOST)
		
	# Compiler Flags and Defines
	CC = gcc
	DUMP = objdump
	LDFLAGS = -Wl,-Map=$(OUTPUT).map
	CFLAGS = $(INCLUDES) -Wall -Werror -g -O0 -std=c99 -DHOST

else ifeq ($(PLATFORM),MSP432)
	
	# Architecture Specific Flags
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
		
	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	DUMP = arm-none-eabi-objdump
	LDFLAGS = -Wl,-Map=$(OUTPUT).map -T $(LINKER_FILE)
	CFLAGS = $(INCLUDES) -Wall -Werror -g -O0 -std=c99 -DMSP432 -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
endif

PREPROCESSED_FILES = $(SOURCES:.c=.i)
ASSEMBLY_FILES = $(SOURCES:.c=.asm)
OBJECT_FILES = $(SOURCES:.c=.o)


# Generate the preprocessed output of all c-program implementation files.
%.i: %.c
	$(CC) -E $< $(CFLAGS) -o $@


# Generate assembly output of c-program implementation files and the final output executable.
%.asm: %.c $(OUTPUT).out
	$(CC) -S $< $(CFLAGS) -o $@
	$(DUMP) -d $(OUTPUT).out > $(OUTPUT).dump
	

# Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.
%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@


# Compile all object files, but do not link.
.PHONY: compile-all
compile-all: $(OBJECT_FILES)


# Compile all object files and link into a final executable.
.PHONY: build
build: $(OUTPUT).out


$(OUTPUT).out: $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) $(CFLAGS) $(LDFLAGS) -o $@


# Remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
.PHONY: clean
clean:
	rm -f $(PREPROCESSED_FILES) $(ASSEMBLY_FILES) $(OBJECT_FILES) $(OUTPUT).map $(OUTPUT).out $(OUTPUT).dump

