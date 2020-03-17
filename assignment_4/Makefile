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
# Build system based on GNU tools, GCC and GNU make. It supports two 
# platforms: the host environment and the target embedded system MSP432.
#
# Use: make [TARGET] [PLATFORM OVERRIDES] [VERBOSITY]
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
#      PLATFORM=HOST - host environment
#      PLATFORM=MSP432 - target embedded system
#
# Verbosity:
#      VERBOSE=ENABLED - verbose mode on
#
# Author: Michal Soloducha
# Date: 2020-03-17
#
#-----------------------------------------------------------------------------

include sources.mk

# output name
OUTPUT = c1Final


ifeq ($(PLATFORM),HOST)
		
	# Compiler Flags and Defines
	CC = gcc
	DUMP = objdump
	LDFLAGS = 
	CFLAGS = $(INCLUDES) -Wall -g -O0 -std=c99 -DCOURSE1 -DHOST

	ifeq ($(VERBOSE), ENABLED)
		CFLAGS += -DVERBOSE
	endif

else ifeq ($(PLATFORM),MSP432)
	
	# Architecture Specific Flags
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
		
	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LDFLAGS = -T $(LINKER_FILE)
	CFLAGS = $(INCLUDES) -Wall -g -O0 -std=c99 -DCOURSE1 -DVERBOSE -DMSP432 -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
endif


OBJECT_FILES = $(SOURCES:.c=.o)


# Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.
%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@


# Compile all object files and link into a final executable.
.PHONY: build
build: $(OUTPUT).out


$(OUTPUT).out: $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) $(CFLAGS) $(LDFLAGS) -o $@


# Remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
.PHONY: clean
clean:
	rm -f $(OBJECT_FILES) $(OUTPUT).map $(OUTPUT).out

