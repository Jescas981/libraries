#include <dsc/cdynarray.h>
#include <stdio.h>
#include <unity.h>

void setUp(void) {}

void tearDown(void) {}

void test_adt(void) {
  int* arr = dynarray_create();
<<<<<<< HEAD
  dynarray_add(&arr, 15);
  dynarray_add(&arr, 45);
  printf("%i", arr[0]);
  printf("%i", arr[1]);
  printf("hola");
=======
  for (size_t i = 0; i < 100; i++) {
    dynarray_add(&arr, (i + 1) * 15, int);
  }
  for (size_t i = 0; i < dynarray_length(arr); i++) {
    printf("%i ", arr[i]);
  }
>>>>>>> 0f2bc86 (Add MSC support)
}

int main(int argc, char* argv[]) {
  UNITY_BEGIN();
  RUN_TEST(test_adt);
  return UNITY_END();
}