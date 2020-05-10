#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array_ptr create_array(int length)
{
  Array_ptr array = (Array_ptr)malloc(sizeof(Array));
  array->length = length;
  array->array = (int *)malloc(sizeof(int) * length);
  return array;
}

Array_ptr create_and_initialize_array(int *src, int length)
{
  Array_ptr array = create_array(length);
  for (int index = 0; index < length; index++)
  {
    array->array[index] = src[index];
  }
  return array;
}

Array_ptr map(Array_ptr src, Mapper mapper)
{
  Array_ptr array = create_array(src->length);
  for (int index = 0; index < src->length; index++)
  {
    array->array[index] = mapper(src->array[index]);
  }
  return array;
}

Array_ptr filter(Array_ptr src, Predicate predicate)
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

int reduce(Array_ptr src, int init, Reducer reducer)
{
  int context = init;
  for (int index = 0; index < src->length; index++)
  {
    context = reducer(context, src->array[index]);
  }
  return context;
}
