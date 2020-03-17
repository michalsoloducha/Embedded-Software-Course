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
 * @file data.h
 * @brief Integer to ASCII string and reverse converters
 *
 * This header file provide two functions for converting 
 * an integer type variable into ASCII string and reverse.
 *
 * @author Michal Soloducha
 * @date March 15 2020
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Converts integer into ASCII string 
 *
 * Given a pointer to a memory location, this will convert 
 * given integer into an ASCII string. The function handles signed data. 
 * There is a null terminator at the end of the converted string.
 *
 * @param data Signed 32-bit integer variable to convert
 * @param ptr Pointer to memory location
 * @param base Conversion base (2-16)
 *
 * @return digits Number of elements in converted string
 *   (incl. sign and null terminator)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint8_t base);

/**
 * @brief Converts ASCII string into integer
 *
 * Given a pointer to a memory location, this will convert 
 * given ASCII string into integer. The function handles signed data. 
 * There is a null terminator at the end of the converted string.
 *
 * @param ptr Pointer to memory location
 * @param digits Number of elements in ASCII string
 *   (incl. sign and null terminator)
 * @param base Conversion base (2-16)
 *
 * @return data Converted signed 32-bit integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
