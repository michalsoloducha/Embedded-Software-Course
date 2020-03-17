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
 * @file misc.h 
 * @brief This file is to be used for the c1m2 assesment
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */
#include "misc.h"

                            //   name:        segment:  sub-segment:  permissions:  lifetime:
#define SOME_VALUE (6)      // v SOME_VALUE,  none,     none,         none,         none

int g5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int func(int * f1)          // v f1,          data,     stack,        read-write,   function/block
                            // v func(),      code,     text,         read,         program
{
  static int f2;            // v f2,          data,     BSS,          read-write,   program
  unsigned int f3 = 0;      // v f3,          data,     stack,        read-write,   function/block

  volatile char * f4 = "Hello World!\n";
                            // ? f4,          data,     stack,        read-write,   function/block
                            // v "Hello...",  code,     rodata,       read,         program 
  f2++;
  *(&g5[0] + f2) = f3;

  for (f3 = 0; f3 < SOME_VALUE; f3++)
  {
    g5[f3] = f4[f3];
    f2++;
  }

  return f2;
}

