/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Statistical Analytics Program Implementation
 *
 * This file contains the implementation of functions that perform statistical analysis 
 * on an array of unsigned char data. The functions include finding minimum, maximum, 
 * mean, and median values, sorting the array in descending order, and printing results to the console.
 *
 * @author Sudara Buddhika
 * @date 2025-08-04
 */

#include "stats.h"
#include "platform.h"

void print_statistics(unsigned char *data, unsigned int length) {
    PRINTF("Statistical Analysis:\n");
    PRINTF("Minimum: %d\n", find_minimum(data, length));
    PRINTF("Maximum: %d\n", find_maximum(data, length));
    PRINTF("Mean: %d\n", find_mean(data, length));
    PRINTF("Median: %d\n", find_median(data, length));
}

void print_array(unsigned char *data, unsigned int length) {
#ifdef VERBOSE
    PRINTF("Array Data:\n");
    for (unsigned int i = 0; i < length; i++) {
        PRINTF("data[%d] = %d\n", i, data[i]);
    }
    PRINTF("\n");
#endif
}

unsigned char find_median(unsigned char *data, unsigned int length) {
    // Create a copy of the array to avoid modifying original
    unsigned char temp[length];
    for (unsigned int i = 0; i < length; i++) {
        temp[i] = data[i];
    }
    
    // Sort the temporary array
    sort_array(temp, length);
    
    // Find median
    if (length % 2 == 0) {
        // Even number of elements - average of middle two
        return (temp[length/2 - 1] + temp[length/2]) / 2;
    } else {
        // Odd number of elements - middle element
        return temp[length/2];
    }
}

unsigned char find_mean(unsigned char *data, unsigned int length) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < length; i++) {
        sum += data[i];
    }
    return (unsigned char)(sum / length);
}

unsigned char find_maximum(unsigned char *data, unsigned int length) {
    unsigned char max = data[0];
    for (unsigned int i = 1; i < length; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

unsigned char find_minimum(unsigned char *data, unsigned int length) {
    unsigned char min = data[0];
    for (unsigned int i = 1; i < length; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

void sort_array(unsigned char *data, unsigned int length) {
    // Simple bubble sort in descending order
    for (unsigned int i = 0; i < length - 1; i++) {
        for (unsigned int j = 0; j < length - i - 1; j++) {
            if (data[j] < data[j + 1]) {
                // Swap elements
                unsigned char temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}