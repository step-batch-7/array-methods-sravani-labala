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
  long int total = (long int)a + (long int)b;
  return (Object)total;
}

Bool is_odd_void(Object number)
{
  return (int)number % 2 ? False : True;
}

Object square_void(Object number)
{
  long int result = (long int)number * (long int)number;
  return (Object)result;
}

void display_number_array(ArrayVoid_ptr array)
{
  for (int index = 0; index < array->length; index++)
  {
    printf("%d ", (int)array->array[index]);
  }
  printf("\n");
}

void display_character_array(ArrayVoid_ptr array)
{
  for (int index = 0; index < array->length; index++)
  {
    printf("%c ", (char)array->array[index]);
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

  ArrayVoid_ptr array_void = create_array_void(length);
  array_void->array[0] = (Object)(1);
  array_void->array[1] = (Object)(2);
  array_void->array[2] = (Object)(3);
  array_void->array[3] = (Object)(4);
  array_void->array[4] = (Object)(5);
  ArrayVoid_ptr empty_array_void = create_array_void(0);

  display_number_array(array_void);
  display_number_array(map_void(array_void, square_void));
  display_number_array(map_void(empty_array_void, square_void));
  display_number_array(filter_void(array_void, is_odd_void));
  display_number_array(filter_void(empty_array_void, is_odd_void));
  printf("%d\n", (int)reduce_void(array_void, 0, add_void));
  printf("%d\n", (int)reduce_void(empty_array_void, 0, add_void));

  return 0;
}