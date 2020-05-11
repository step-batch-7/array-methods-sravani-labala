#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H

#include "array.h"

typedef void *Object;

typedef Object (*MapperVoid)(Object);
typedef Bool (*PredicateVoid)(Object);
typedef Object (*ReducerVoid)(Object, Object);

typedef void (*Displayer)(Object);
typedef Object (*typeMalloc)(Object, int);

typedef struct
{
  Object *array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;

ArrayVoid_ptr create_array_void(int length);

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper);
ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate);
Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer);

void display_number(Object value);
void display_character(Object value);
void display_array_void(ArrayVoid_ptr array, Displayer displayer);

Object create_number(Object array, int inc);
Object create_character(Object array, int inc);
ArrayVoid_ptr create(Object array, int length, typeMalloc type);

#endif