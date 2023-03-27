#include <dsc/cdynarray.h>
#include <stdio.h>
#include <unity.h>

void setUp(void) {}

void tearDown(void) {}

void test_adt(void) {
  int* arr = dynarray_create();
  for (size_t i = 0; i < 600; i++) {
    dynarray_add(&arr, (i + 1) * 15, int);
  }
  for (size_t i = 0; i < dynarray_length(arr); i++) {
    printf("%i ", arr[i]);
  }
}

int main(int argc, char* argv[]) {
  UNITY_BEGIN();
  RUN_TEST(test_adt);
  return UNITY_END();
}