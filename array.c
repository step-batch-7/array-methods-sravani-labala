#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array *create_array(int length)
{
  Array *array = (Array *)malloc(sizeof(Array));
  array->length = length;
  array->array = (int *)malloc(sizeof(int) * length);
  return array;
}

Array *create_and_initialize_array(int *src, int length)
{
  Array *array = create_array(length);
  for (int index = 0; index < length; index++)
  {
    array->array[index] = src[index];
  }
  return array;
}

Array *map(Array *src, Mapper mapper)
{
  Array *array = create_array(src->length);
  for (int index = 0; index < src->length; index++)
  {
    array->array[index] = mapper(src->array[index]);
  }
  return array;
}

Array *filter(Array *src, Predicate predicate)
{
  int temp[src->length], count = 0;
  for (int index = 0; index < src->length; index++)
  {
    Bool status = predicate(src->array[index]);
    if (status)
    {
      temp[count] = src->array[index];
      count++;
    }
  }
  return create_and_initialize_array(temp, count);
}

int reduce(Array *src, int init, Reducer reducer)
{
  int context = init;
  for (int index = 0; index < src->length; index++)
  {
    context = reducer(context, src->array[index]);
  }
  return context;
}
