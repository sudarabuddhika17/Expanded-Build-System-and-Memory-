#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include "platform.h"

/**
 * @brief Integer to ASCII conversion
 *
 * @param data The integer to convert
 * @param ptr Pointer to store the converted string
 * @param base The base for conversion (2-16)
 * @return Length of the converted string including null terminator
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief ASCII to Integer conversion
 *
 * @param ptr Pointer to the string to convert
 * @param digits Number of digits in the string
 * @param base The base for conversion (2-16)
 * @return The converted integer value
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
