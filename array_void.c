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

void display_number(Object value)
{
  printf("%d ", *(int *)value);
}

void display_character(Object value)
{
  printf("%c ", *(char *)value);
}

void display_array_void(ArrayVoid_ptr array, Displayer displayer)
{
  for (int index = 0; index < array->length; index++)
  {
    (*displayer)(array->array[index]);
  }
  printf("\n");
}

Object create_number(Object array, int inc)
{
  Object int_ptr = malloc(sizeof(int));
  *(int *)int_ptr = *((int *)array + inc);
  return int_ptr;
}

Object create_character(Object array, int inc)
{
  Object char_ptr = malloc(sizeof(char));
  *(char *)char_ptr = *((char *)array + inc);
  return char_ptr;
}

ArrayVoid_ptr create(Object array, int length, typeMalloc type)
{
  ArrayVoid_ptr array_void = create_array_void(length);
  for (int i = 0; i < length; i++)
  {
    array_void->array[i] = (*type)(array, i);
  }
  return array_void;
}