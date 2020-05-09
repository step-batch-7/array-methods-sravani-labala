#include <stdio.h>
#include <stdlib.h>
#include "array.h"

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

void display_array(Array *array)
{
  for (int index = 0; index < array->length; index++)
  {
    printf("%d ", array->array[index]);
  }
  printf("\n");
}

int main(void)
{
  int stack_array[] = {1, 2, 3, 4, 5};
  int length = sizeof(stack_array) / sizeof(int);
  Array *array = create_and_initialize_array(stack_array, length);
  Array *empty_array = create_array(0);

  display_array(array);                        //displaying the array elements
  display_array(map(array, square));           //testing map with some elements in array
  display_array(map(empty_array, square));     //testing map with empty array
  display_array(filter(array, is_odd));        //testing filter with some elements in array
  display_array(filter(empty_array, is_odd));  //testing filter with empty array
  printf("%d\n", reduce(array, 0, sum));       //testing reduce with some elements in array
  printf("%d\n", reduce(empty_array, 0, sum)); //testing reduce with empty array

  return 0;
}