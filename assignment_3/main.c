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
 * @file main.c
 * @brief This file is to be used for the c1m3 assessment.
 *
 * This file provides various memory allocations. The learner will need
 * to analyze the code's memory footprint for this assessment.
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include "misc.h"

                        //   name:      segment:  sub-segment:  permissions: lifetime:
static int g1;          // v g1         data,     BSS,          RW,          program
const int g2 = 45;      // v g2,        code,     const/rodata, read,        program
char g3 = 12;           // v g3,        data,     data,         RW,          program
char g4 = 0;            // v g4,        data,     BSS,          RW,          program
extern char g5[N];      // v g5,        data,     data,         RW,          program
                        // v N,         none,     none,         none,        none

int main()              // v main(),    code,     text,         read,        program
{
  register int l1;      // v l1,        register, none,         RW,          function/block
  int * l2;             // v l2,        data,     stack,        RW,          function/block
  volatile int l3 = 12; // v l3,        data,     stack,        RW,          function/block
  
  l2 = (int *) malloc( N * g2 * sizeof(char) );
                        // v deref. l2, data,     heap,         RW,          indefinite

  if ( ! l2 )
  {
    return -1;
  }

  for( l1 = 0; l1 < g2; l3++)
  {
    g1 = func(l2);
  }

  return 0;
}

