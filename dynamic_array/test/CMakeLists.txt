include(FetchContent)

FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG       v2.5.0
)

FetchContent_MakeAvailable(unity)

add_executable(dynarray_c_test dynarray.c)
include_directories(dynarray_c_test ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(dynarray_c_test PRIVATE dynarray_c unity)
