cmake_minimum_required(VERSION 3.0)

#message("CMAKE_SOURCE_DIR= ${CMAKE_SOURCE_DIR}")
#message("CMAKE_BINARY_DIR= ${CMAKE_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

project(SAT_APP)

add_subdirectory(app)
add_subdirectory(str_util)
add_subdirectory(libs)

enable_testing()
