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
#include "my_set.h"

char arr[LENGTH];

void set(char * ptr, int size, char value){
  int i;
  for(i = 0; i < size; i++) {
    ptr[i] = value;
  }
}

