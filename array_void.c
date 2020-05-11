#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_array_void(int length)
{
  ArrayVoid_ptr array_void = (ArrayVoid_ptr)malloc(sizeof(ArrayVoid));
  array_void->length = length;
  array_void->array = (Object *)malloc(sizeof(Object) * length);
  return array_void;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr array = create_array_void(src->length);
  for (int index = 0; index < src->length; index++)
  {
    array->array[index] = (*mapper)(src->array[index]);
  }
  return array;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object temp[src->length];
  int count = 0;
  for (int index = 0; index < src->length; index++)
  {
    Bool status = (*predicate)(src->array[index]);
    if (status)
    {
      temp[count] = src->array[index];
      count++;
    }
  }
  ArrayVoid_ptr array_void = create_array_void(count);
  for (int index = 0; index < count; index++)
  {
    array_void->array[index] = temp[index];
  }
  return array_void;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  Object context = init;
  for (int index = 0; index < src->length; index++)
  {
    context = (*reducer)(context, src->array[index]);
  }
  return context;
}