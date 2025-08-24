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
 * @file stats.h 
 * @brief Statistical Analytics Program
 *
 * This header file contains the declarations of functions that perform statistical analysis on an array of unsigned char data. The functions include finding minimum, maximum, mean, and median values, sorting the array in descending order, and printing results to the console.
 *
 * @author Sudara Buddhika
 * @date 2025-08-04
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Prints the statistics of the array
 *
 * This function prints the minimum, maximum, mean, and median
 * of the given data array to the console.
 *
 * @param data Pointer to the data array
 * @param length Number of elements in the array
 */
void print_statistics(unsigned char *data, unsigned int length);

/**
 * @brief Prints the elements of the array
 *
 * This function prints all elements of the given data array
 * to the console in a formatted way.
 *
 * @param data Pointer to the data array
 * @param length Number of elements in the array
 */
void print_array(unsigned char *data, unsigned int length);

/**
 * @brief Finds the median value of the array
 *
 * This function returns the median value from the given data array.
 * The array should be sorted before finding the median.
 *
 * @param data Pointer to the data array
 * @param length Number of elements in the array
 * @return The median value
 */
unsigned char find_median(unsigned char *data, unsigned int length);

/**
 * @brief Calculates the mean of the array
 *
 * This function calculates and returns the mean value (rounded down)
 * of the data in the array.
 *
 * @param data Pointer to the data array
 * @param length Number of elements in the array
 * @return The mean value
 */
unsigned char find_mean(unsigned char *data, unsigned int length);

/**
 * @brief Finds the maximum value in the array
 *
 * This function scans through the array and returns the largest value.
 *
 * @param data Pointer to the data array
 * @param length Number of elements in the array
 * @return The maximum value
 */
unsigned char find_maximum(unsigned char *data, unsigned int length);

/**
 * @brief Finds the minimum value in the array
 *
 * This function scans through the array and returns the smallest value.
 *
 * @param data Pointer to the data array
 * @param length Number of elements in the array
 * @return The minimum value
 */
unsigned char find_minimum(unsigned char *data, unsigned int length);

/**
 * @brief Sorts the array from largest to smallest
 *
 * This function sorts the data array in-place in descending order.
 * The largest value will be at index 0 after sorting.
 *
 * @param data Pointer to the data array
 * @param length Number of elements in the array
 */
void sort_array(unsigned char *data, unsigned int length);



#endif /* __STATS_H__ */
