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
 * @brief Integer to ASCII string and reverse converters
 *
 * This implementation file provide two functions for converting 
 * an integer type variable into ASCII string and reverse.
 *
 * @author Michal Soloducha
 * @date March 15 2020
 *
 */

#include <stdint.h>
#include <stdlib.h>
#include "data.h"
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t my_itoa( int32_t data, uint8_t * ptr, uint8_t base){
	uint8_t* ptrToReverse = NULL;
	uint8_t digits = 0;
	uint8_t digitsToReverse = 0;

	if ( data < 0){
		*(ptr++) = '-';
		data = abs(data);
		digits++;
	}

	ptrToReverse = ptr;
	while ( data > 0){
		*(ptr++) = data % base + '0'; // 0's ASCII value is 48
		data /= base;
		digits++;
		digitsToReverse++;
	}

	my_reverse( ptrToReverse, digitsToReverse);

	*ptr = 0;
	digits++;

	return digits;
}

int32_t my_atoi( uint8_t * ptr, uint8_t digits, uint32_t base){
	_Bool isNegative = 0;
	uint8_t trueDigits = digits - 1;
	int i;
	int32_t data = 0;
	uint32_t power = 1;

	if ( *ptr == 45){
		isNegative = 1;
		trueDigits--;
		ptr++;
	}

	for (i = trueDigits - 1; i >= 0; i--){
		data += (*(ptr + i) - 48) * power; // 0's ASCII value is 48
		power = power * base;
	}	

	if (isNegative == 1){
		data = -data;
	}

	return data;
}
