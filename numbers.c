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

void test_array_methods()
{
  int stack_array[] = {1, 2, 3, 4, 5};
  int length = sizeof(stack_array) / sizeof(int);
  Array_ptr array = create_and_initialize_array(stack_array, length);
  Array_ptr empty_array = create_array(0);

  display_array(array);                         //displaying the array elements
  display_array(map(array, &square));           //testing map with some elements in array
  display_array(map(empty_array, &square));     //testing map with empty array
  display_array(filter(array, &is_odd));        //testing filter with some elements in array
  display_array(filter(empty_array, &is_odd));  //testing filter with empty array
  printf("%d\n", reduce(array, 0, &sum));       //testing reduce with some elements in array
  printf("%d\n", reduce(empty_array, 0, &sum)); //testing reduce with empty array
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

Bool is_vowel(Object character)
{
  char ch = *(char *)character;
  Bool is_lower_vowel = ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  Bool is_upper_vowel = ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
  return is_lower_vowel || is_upper_vowel;
}

Object to_lower(Object character)
{
  Object result = malloc(sizeof(char));
  char ch = *(char *)character;
  if (ch > 64 && ch < 91)
  {
    ch = ch + 32;
  }
  *(char *)result = ch;
  return result;
}

void test_array_void_methods()
{
  int values[] = {1, 2, 3, 4, 5};
  ArrayVoid_ptr array_void = create(&values, 5, &create_number);
  ArrayVoid_ptr empty_array_void = create_array_void(0);

  display_array_void(array_void, &display_number);                                  //displaying the array_void_elements
  display_array_void(map_void(array_void, &square_void), &display_number);          //testing map with some elements in array_void
  display_array_void(map_void(empty_array_void, &square_void), &display_number);    //testing map with empty array_void
  display_array_void(filter_void(array_void, &is_odd_void), &display_number);       //testing filter with some elements in array_void
  display_array_void(filter_void(empty_array_void, &is_odd_void), &display_number); //testing filter with empty array_void

  char characters[] = "SoMeThInG";
  ArrayVoid_ptr char_array_void = create(&characters, 10, &create_character);      //displaying the character_array
  display_array_void(map_void(char_array_void, &to_lower), &display_character);    //testing map with some character elements
  display_array_void(filter_void(char_array_void, &is_vowel), &display_character); //testing filter with some character elements

  int *context = malloc(sizeof(int));
  *context = 0;

  printf("%d\n", *(int *)reduce_void(array_void, context, &add_void));       //testing reduce with some elements in array_void
  printf("%d\n", *(int *)reduce_void(empty_array_void, context, &add_void)); //testing reduce with empty array_void
}

int main(void)
{
  test_array_methods();
  printf("\n");
  test_array_void_methods();
  return 0;
}