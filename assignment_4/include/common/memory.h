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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick, Michal Soloducha
 * @date 2020-02-28
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);


/**
 * @brief Moves from source to destination
 *
 * Given a pointer to a source and destination memory locations, 
 * this will move given number of bytes 
 * with no data corruption in case of an overlap.
 *
 * @param src Pointer to source memory location
 * @param dst Pointer to destination memory location
 * @param length Number of bytes to move
 *
 * @return Pointer to destination memory location
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @brief Copies from source to destination
 *
 * Given a pointer to a source and destination memory locations, 
 * this will copy given number of bytes
 * with possible data corruption in case of an overlap.
 *
 * @param src Pointer to source memory location
 * @param dst Pointer to destination memory location
 * @param length Number of bytes to copy
 *
 * @return Pointer to destination memory location
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @brief Sets memory location to given value
 *
 * Given a pointer to a memory location, 
 * this will set given number of bytes to a given value.
 *
 * @param src Pointer to memory location
 * @param length Number of bytes to set
 * @param value Value to set
 *
* @return Pointer to memory location
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);


/**
 * @brief Sets memory location to zero
 *
 * Given a pointer to a memory location, 
 * this will set given number of bytes to zero.
 *
 * @param src Pointer to memory location
 * @param length Number of bytes to set
 *
* @return Pointer to memory location
 */
uint8_t * my_memzero(uint8_t * src, size_t length);


/**
 * @brief Reverses byte order in memory location
 *
 * Given a pointer to a memory location,
 * this will reverse the order of given number of bytes.
 *
 * @param src Pointer to memory location
 * @param length Number of bytes to reverse
 *
* @return Pointer to memory location
 */
uint8_t * my_reverse(uint8_t * src, size_t length);


/**
 * @brief Allocates dynamic memory
 *
 * Given a number of words,
 * this will allocate them in dynamic memory.
 *
 * @param length Number of words to allocate
 *
* @return Pointer to memory if successful, NULL if not successful
 */
uint32_t * reserve_words(size_t length);


/**
 * @brief Frees dynamic memory allocation
 *
 * Given a pointer to a function,
 * this will free a dynamic memory allocation.
 *
 * @param src Pointer to function
 *
* @return void
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
