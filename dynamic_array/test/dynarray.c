#include <dsc/cdynarray.h>
#include <stdio.h>
#include <unity.h>

void setUp(void) {}

void tearDown(void) {}

void test_adt(void) {
  int* arr = dynarray_create();
  dynarray_add(&arr, 15);
  dynarray_add(&arr, 45);
  printf("%i", arr[0]);
  printf("%i", arr[1]);
  printf("hola");
}

int main(int argc, char* argv[]) {
  UNITY_BEGIN();
  RUN_TEST(test_adt);
  return UNITY_END();
}