cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

add_library(easyloggingpp STATIC easylogging++.cc)

target_include_directories(easyloggingpp PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

#target_include_directories(str_util_static PUBLIC
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#)
