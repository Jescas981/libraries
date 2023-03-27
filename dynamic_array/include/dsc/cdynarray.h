#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stdbool.h>
#include <stdlib.h>

#define DYNARRAY_GROW 3

<<<<<<< HEAD
#ifdef _MSC_VER
#define DYNARRAY_TYPEOF(value) _typeof(value)
#else
#define DYNARRAY_TYPEOF(value) typeof(value)
#endif

=======
>>>>>>> 0f2bc86 (Add MSC support)
typedef struct dynarray_data dynarray_data;
// Dont' use this type in your code, it only works to make this library generic
typedef void* dynarray;

/**
 * @brief Allocates a new empty Dynarray in heap
 * @return A Dynarray pointer
 */
dynarray dynarray_create(void);

/**
 * @brief Delete Dynamic Array
 * @param arr Dynamic Array to free
 */
<<<<<<< HEAD
dynarray dynarray_free(dynarray arr);
=======
void dynarray_free(dynarray arr);

/**
 * @brief Length of Dynamic Array
 * @param arr Dynarray pointer
 */
size_t dynarray_length(dynarray arr);

/**
 * @brief Capacity of Dynamic Array
 * @param arr Dynarray pointer
 */
size_t dynarray_capacity(dynarray arr);
>>>>>>> 0f2bc86 (Add MSC support)

/**
 * @brief Allocates a new Dynarray in heap with reserved capacity
 * @param capacity How much memory to allocate
 * @param size_type The size of the type
 * @return A Dynarray pointer
 */
dynarray dynarray_alloc(size_t capacity, size_t size_type);

<<<<<<< HEAD
=======
#ifndef _MSC_VER
>>>>>>> 0f2bc86 (Add MSC support)
/**
 * @brief Add a new elemnent ot dynamic array
 * @param dynarray_ptr Dynarray pointer
 * @param value Item to add
 * @attention This function can make previous pointers invalid
 */
<<<<<<< HEAD

#define dynarray_add(dynarray_ptr, value)                           \
  *((DYNARRAY_TYPEOF(value)*)_dynarray_add((dynarray*)dynarray_ptr, \
                                           sizeof(value))) = value;
=======
#define dynarray_add(dynarray_ptr, value)                                    \
  *((typeof(value)*)_dynarray_add((dynarray*)dynarray_ptr, sizeof(typeof(value)))) = \
      value;
#else
/**
 * @brief Add a new elemnent ot dynamic array
 * @param dynarray_ptr Dynarray pointer
 * @param value Item to add
 * @param type Type of item
 * @attention This function can make previous pointers invalid
 */
#define dynarray_add(dynarray_ptr, value, type) \
  *((type*)_dynarray_add((dynarray*)dynarray_ptr, sizeof((type)value))) = value;
#endif  // !1
>>>>>>> 0f2bc86 (Add MSC support)

/**
 * @brief Add an empty memory block to dynamic array
 * @param arr Dynarray pointer
 * @param size_type The size of the type
 * @return A Dynarray pointer to the last element added previously
 * @attention This function can make previous pointers invalid
 */
dynarray _dynarray_add(dynarray* arr, size_t size_type);

#endif