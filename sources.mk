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

# Common sources for both platforms
COMMON_SOURCES = src/main.c src/memory.c src/stats.c src/data.c src/course1.c

# Platform-specific sources
HOST_SOURCES = $(COMMON_SOURCES)
MSP432_SOURCES = $(COMMON_SOURCES) \
                 src/startup_msp432p401r_gcc.c \
                 src/system_msp432p401r.c \
                 src/interrupts_msp432p401r_gcc.c

# Common includes
COMMON_INCLUDES = -Iinclude/common

# Platform-specific includes
HOST_INCLUDES = $(COMMON_INCLUDES)
MSP432_INCLUDES = $(COMMON_INCLUDES) -Iinclude/msp432 -Iinclude/CMSIS

