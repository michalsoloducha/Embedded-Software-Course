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
#
# Author: Michal Soloducha
# Date: 2020-03-05
#
#-----------------------------------------------------------------------------

ifeq ($(PLATFORM),HOST)

	SOURCES = ./src/main.c \
		 ./src/memory.c \
		 ./src/course1.c \
		 ./src/stats.c \
		 ./src/data.c

	INCLUDES = -I./include/common

else ifeq ($(PLATFORM),MSP432)

	SOURCES = ./src/main.c \
		 ./src/memory.c \
		 ./src/course1.c \
		 ./src/stats.c \
		 ./src/data.c \
		 ./src/interrupts_msp432p401r_gcc.c \
		 ./src/startup_msp432p401r_gcc.c \
		 ./src/system_msp432p401r.c

	INCLUDES = -I./include/common \
		  -I./include/msp432 \
		  -I./include/CMSIS
endif

