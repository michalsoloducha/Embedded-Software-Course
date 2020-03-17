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
 * @brief Statistics
 *
 * Program performing simple statistics on array of numbers
 *
 * @author Michal Soloducha
 * @date 2020-02-02
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Prints array statistics
 *
 * A function that prints the statistics of an array including minimum, maximum, mean, and median
 *
 * @param ptr Pointer to data array
 * @param size Size of data array
 *
 * @return void
 */
void print_statistics(unsigned char *ptr, unsigned int size);

/**
 * @brief Prints array
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param ptr Pointer to data array
 * @param size Size of data array
 *
 * @return void
 */
void print_array(unsigned char *ptr, unsigned int size);

/**
 * @brief Calculates array median value
 *
 * Given an array of data and a length, returns the median value
 *
 * @param ptr Pointer to data array
 * @param size Size of data array
 *
 * @return Array median value
 */
unsigned char find_median(unsigned char *ptr, unsigned int size);

/**
 * @brief Calculates array mean
 *
 * Given an array of data and a length, returns the mean
 *
 * @param ptr Pointer to data array
 * @param size Size of data array
 *
 * @return Array mean
 */
unsigned char find_mean(unsigned char *ptr, unsigned int size);

/**
 * @brief Calculates array maximum
 *
 * Given an array of data and a length, returns the maximum
 *
 * @param ptr Pointer to data array
 * @param size Size of data array
 *
 * @return Array maximum
 */
unsigned char find_maximum(unsigned char *ptr, unsigned int size);

/**
 * @brief Calculates array minimum
 *
 * Given an array of data and a length, returns the minimum
 *
 * @param ptr Pointer to data array
 * @param size Size of data array
 *
 * @return Array minimum
 */
unsigned char find_minimum(unsigned char *ptr, unsigned int size);

/**
 * @brief Sorts array
 *
 * Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * @param ptr Pointer to data array
 * @param size Size of data array
 *
 * @return void
 */
void sort_array(unsigned char *ptr, unsigned int size);

#endif /* __STATS_H__ */
