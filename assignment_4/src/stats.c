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
 * @brief Statistics
 *
 * Program performing simple statistics on array of numbers
 *
 * @author Michal Soloducha
 * @date 2020-02-02
 *
 */



#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/*int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  unsigned char *ptr = test;


  printf("\nInput array:\n");  
  print_array(ptr, SIZE);
  print_statistics(ptr, SIZE);
  sort_array(ptr, SIZE);
  printf("\nSorted array:\n");
  print_array(ptr, SIZE);

  return 0;
}*/

void print_statistics(unsigned char *ptr, unsigned int size) {
  printf("\nBasic statistics of input array:\n");
  printf("\nMinimum value: %d", find_minimum(ptr, size));
  printf("\nMaximum value: %d", find_maximum(ptr, size));
  printf("\nAverage value: %d", find_mean(ptr, size));
  // printf("\nMedian value: %d\n", find_median(ptr, size));
}

void print_array(unsigned char *ptr, unsigned int size) {
  #ifdef VERBOSE
    printf("\n");
    for( int i = 0; i < size; i++ ) {   
      printf("%d ", ptr[i]);
    }
    printf("\n");
  #endif
}

/*unsigned char find_median(unsigned char array[], unsigned int size) {
  sort_array(array, size);
  unsigned char a = array[(int)floor(((double)size+1)/2-1)];
  unsigned char b = array[(int)ceil(((double)size+1)/2-1)];
  return ( (unsigned char)(a + b) / 2 );
}*/

unsigned char find_mean(unsigned char *ptr, unsigned int size) {
  unsigned int sum = 0;
  for ( int i = 0; i < size; i++) {
    sum += *(ptr + i);
  }
  return sum / size;
}

unsigned char find_maximum(unsigned char *ptr, unsigned int size) {

  unsigned char max = *ptr;

  for ( int i = 1; i < size; i++) {
    if (*(ptr + i) > max) {
      max = *(ptr + i);
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char *ptr, unsigned int size) {

  unsigned char min = *ptr;

  for ( int i = 1; i < size; i++) {
    if (*(ptr + i) < min) {
      min = *(ptr + i);
    }
  }
  return min;
}

void sort_array(unsigned char *ptr, unsigned int size) {
  int compare(const void *a, const void *b) {
    return (-1 * ( *(unsigned char*)a - *(unsigned char*)b ));
  }
  qsort(ptr, size, sizeof(char), compare);
}
