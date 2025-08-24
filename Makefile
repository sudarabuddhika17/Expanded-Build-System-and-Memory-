#******************************************************************************
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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST
TARGET = c1m2.out
MAP_FILE = c1m2.map

# Architectures Specific Flags
LINKER_FILE = -T msp432p401r.lds
CPU = -mcpu=cortex-m4
ARCH = -mthumb -march=armv7e-m
SPECS = --specs=nosys.specs


# Compiler Flags and Defines
CC =
LD =
LDFLAGS =
CFLAGS =
CPPFLAGS =

# Platform-specific settings
ifeq ($(PLATFORM),HOST)
    CC = gcc
    LD = gcc
    CPPFLAGS += -DHOST -DCOURSE1 -DVERBOSE
    CFLAGS = -Wall -Werror -g -O0 -std=c99
    LDFLAGS =
    SOURCES = $(HOST_SOURCES)
    INCLUDES = $(HOST_INCLUDES)
    SIZE = size
endif

ifeq ($(PLATFORM),MSP432)
    CC = arm-none-eabi-gcc
    LD = arm-none-eabi-gcc
    CPPFLAGS = -DMSP432 -DCOURSE1
    CFLAGS = -Wall -Werror -g -O0 -std=c99 $(CPU) $(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16
    LDFLAGS = $(LINKER_FILE) -Wl,-Map=$(MAP_FILE) $(CPU) $(ARCH) -mfloat-abi=hard -mfpu=fpv4-sp-d16 $(SPECS)
    SOURCES = $(MSP432_SOURCES)
    INCLUDES = $(MSP432_INCLUDES)
    SIZE = arm-none-eabi-size
endif

# Object files
OBJS = $(SOURCES:.c=.o)

%.i: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -E $< -o $@

%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: compile-all build clean

compile-all: $(OBJS)

build: compile-all
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) $(OBJS) $(LDFLAGS) -o $(TARGET)
	$(SIZE) $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(MAP_FILE) $(SOURCES:.c=.i) $(SOURCES:.c=.asm) $(SOURCES:.c=.d)

