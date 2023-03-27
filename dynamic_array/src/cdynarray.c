#include <dsc/cdynarray.h>

struct dynarray_data {
  // Meta
  size_t length;
  size_t capacity;
  char data[];  // Flexible array - Takes all remaining space
};

static inline dynarray_data* _dynarray_get_data(dynarray arr) {
  return &(
      (dynarray_data*)
          arr)[-1];  // Decrease pointer address by subtracting the struct size
}

dynarray dynarray_alloc(size_t capacity, size_t size_type) {
  dynarray_data* arr_data =
      (dynarray_data*)malloc(sizeof(dynarray_data) + capacity * size_type);
  arr_data->capacity = capacity;
  arr_data->length = 0;
  return arr_data->data;
}

dynarray_data* _dynarray_realloc(dynarray_data* arr_data, size_t capacity,
                                 size_t size_type) {
  size_t length = arr_data->length;
  dynarray_data* new_data =
      realloc(arr_data, sizeof(dynarray_data) + capacity * size_type);
  new_data->capacity = capacity;
  new_data->length = length;
  return new_data;
}

dynarray dynarray_create(void) {
  dynarray_data* arr_data = (dynarray_data*)malloc(sizeof(dynarray_data));
  return &arr_data->data;
}

dynarray dynarray_free(dynarray arr) {
  dynarray_data* arr_data = _dynarray_get_data(arr);
  free(arr_data);
}

bool _dynarray_is_full(const dynarray const arr) {
  dynarray_data* arr_data = _dynarray_get_data(arr);
  return arr_data->length >= arr_data->capacity;
}

dynarray _dynarray_add(dynarray* arr, size_t size_type) {
  dynarray_data* arr_data = _dynarray_get_data(*arr);
  if (_dynarray_is_full(*arr)) {
    size_t new_capacity =
        (arr_data->capacity == 0 ? 1 : arr_data->capacity) * DYNARRAY_GROW;
    arr_data = _dynarray_realloc(arr_data, new_capacity, size_type);
  }
  return (void*)&arr_data->data[size_type * arr_data->length++];
}
