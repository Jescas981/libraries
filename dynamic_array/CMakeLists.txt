cmake_minimum_required(VERSION 3.12)
project(dynarray LANGUAGES CXX C DESCRIPTION "ADT for dynamic arrays")


include_directories(
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_PREFIX_PATH}/include>
)

add_library(dynarray_c STATIC src/cdynarray.c)

add_subdirectory(test)