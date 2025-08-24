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
 * @file data.c
 * @brief Data manipulation functions
 *
 * This implementation file provides basic data manipulation functions
 * including integer to ASCII and ASCII to integer conversions.
 *
 * @author Your Name
 * @date Date
 *
 */

#include "data.h"
#include "platform.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    uint8_t *temp_ptr = ptr;
    uint8_t length = 0;
    int32_t temp_data = data;
    
    // Handle negative numbers
    if (data < 0) {
        *temp_ptr = '-';
        temp_ptr++;
        length++;
        temp_data = -data;
    }
    
    // Handle zero case
    if (temp_data == 0) {
        *temp_ptr = '0';
        temp_ptr++;
        length++;
    } else {
        // Convert to string
        uint8_t digits[33];
        uint8_t digit_count = 0;
        
        while (temp_data > 0) {
            uint8_t remainder = temp_data % base;
            if (remainder < 10) {
                digits[digit_count] = '0' + remainder;
            } else {
                digits[digit_count] = 'a' + remainder - 10;
            }
            digit_count++;
            temp_data /= base;
        }
        
        // Reverse the digits
        for (int8_t i = digit_count - 1; i >= 0; i--) {
            *temp_ptr = digits[i];
            temp_ptr++;
            length++;
        }
    }
    
    // Add null terminator
    *temp_ptr = '\0';
    length++;
    
    return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    uint8_t is_negative = 0;
    uint8_t *temp_ptr = ptr;
    
    if (*temp_ptr == '-') {
        is_negative = 1;
        temp_ptr++;
        digits--;
    }
    
    for (uint8_t i = 0; i < digits; i++) {
        uint8_t digit_value;
        
        if (*temp_ptr >= '0' && *temp_ptr <= '9') {
            digit_value = *temp_ptr - '0';
        } else if (*temp_ptr >= 'a' && *temp_ptr <= 'f') {
            digit_value = *temp_ptr - 'a' + 10;
        } else if (*temp_ptr >= 'A' && *temp_ptr <= 'F') {
            digit_value = *temp_ptr - 'A' + 10;
        } else {
            break;
        }
        
        if (digit_value >= base) {
            break;
        }
        
        result = result * base + digit_value;
        temp_ptr++;
    }
    
    return is_negative ? -result : result;
}
