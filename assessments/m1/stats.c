/*****************************************************************************
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
 * stats.c
 * Implementation file, for the several statistical functions
 *
 * 

 
 *
 * Abdulmomen Ghalkha
 * 14/11/2024
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);

}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char * array, unsigned int size)
{

  printf("median = %.3f\nmean = %.3f\nmax = %d\nmin = %d\n", find_median(array, size), find_mean(array, size), find_maximum(array, size), find_minimum(array, size));

}

void print_array(unsigned char * array, unsigned int size){
  for (unsigned int i = 0; i < size; i++)
    printf("%d\n", array[i]);

}

float find_median(unsigned char * array, unsigned int size){
  sort_array(array, size);
  float median = 0;
  if (size % 2 == 1)  median = array[size / 2 + 1];
  else median = (array[size / 2 ] + array[size / 2 - 1]) / 2.0;
  return median;

}

float find_mean(unsigned char * array, unsigned int size){
  float mean = 0;
  for (int i = 0; i < size; i++) mean += (unsigned int) array[i];
  return mean /= size;
}

unsigned char find_maximum(unsigned char * array, unsigned int size){
  unsigned char max = 0x00;
  for (int i = 0; i < size; i++)
    if (array[i] > max)
      max = array[i];
  
  return max;
}

unsigned char find_minimum(unsigned char * array, unsigned int size){
  unsigned char min = 0xff;
  for (int i = 0; i < size; i++)
    if (array[i] < min)
      min = array[i];
  
  return min;
}

void sort_array(unsigned char * array, unsigned int size){
  unsigned char element = 0x00;
  for (int i = 0; i < size; i++){
    element = array[i];
    for (int j = i + 1; j < size; j++){
      if (element < array[j]){
        array[i] = array[j];
        array[j] = element;
        element = array[i];
      }
    }
  }
}
