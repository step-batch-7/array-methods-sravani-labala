#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

int sum(int a, int b)
{
  return a + b;
}

Bool is_odd(int number)
{
  return number % 2 ? False : True;
}

int square(int number)
{
  return number * number;
}

void display_array(Array_ptr array)
{
  for (int index = 0; index < array->length; index++)
  {
    printf("%d ", array->array[index]);
  }
  printf("\n");
}

Object add_void(Object a, Object b)
{
  Object result = malloc(sizeof(int));
  *(int *)result = *(int *)a + *(int *)b;
  return result;
}

Bool is_odd_void(Object number)
{
  return *(int *)number % 2 ? False : True;
}

Object square_void(Object number)
{
  Object result = malloc(sizeof(int));
  *(int *)result = *(int *)number * *(int *)number;
  return result;
}

void display_number_array(ArrayVoid_ptr array)
{
  for (int index = 0; index < array->length; index++)
  {
    printf("%d ", *(int *)array->array[index]);
  }
  printf("\n");
}

int main(void)
{
  int stack_array[] = {1, 2, 3, 4, 5};
  int length = sizeof(stack_array) / sizeof(int);
  Array_ptr array = create_and_initialize_array(stack_array, length);
  Array_ptr empty_array = create_array(0);

  display_array(array);                        //displaying the array elements
  display_array(map(array, square));           //testing map with some elements in array
  display_array(map(empty_array, square));     //testing map with empty array
  display_array(filter(array, is_odd));        //testing filter with some elements in array
  display_array(filter(empty_array, is_odd));  //testing filter with empty array
  printf("%d\n", reduce(array, 0, sum));       //testing reduce with some elements in array
  printf("%d\n", reduce(empty_array, 0, sum)); //testing reduce with empty array

  printf("---void array's---\n");

  ArrayVoid_ptr array_void = create_array_void(5);

  int *numbers = malloc(sizeof(int) * array_void->length);
  *(numbers + 0) = 1;
  *(numbers + 1) = 2;
  *(numbers + 2) = 3;
  *(numbers + 3) = 4;
  *(numbers + 4) = 5;
  array_void->array[0] = numbers + 0;
  array_void->array[1] = numbers + 1;
  array_void->array[2] = numbers + 2;
  array_void->array[3] = numbers + 3;
  array_void->array[4] = numbers + 4;

  ArrayVoid_ptr empty_array_void = create_array_void(0);

  display_number_array(array_void);                                 //displaying the array_void_elements
  display_number_array(map_void(array_void, square_void));          //testing map with some elements in array_void
  display_number_array(map_void(empty_array_void, square_void));    //testing map with empty array_void
  display_number_array(filter_void(array_void, is_odd_void));       //testing filter with some elements in array_void
  display_number_array(filter_void(empty_array_void, is_odd_void)); //testing filter with empty array_void

  int *context = malloc(sizeof(int));
  *context = 0;

  printf("%d\n", *(int *)reduce_void(array_void, context, add_void));       //testing reduce with some elements in array_void
  printf("%d\n", *(int *)reduce_void(empty_array_void, context, add_void)); //testing reduce with empty array_void

  return 0;
}