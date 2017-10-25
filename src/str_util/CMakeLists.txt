message("[INFO] CMAKE_CURRENT_SOURCE_DIR= ${CMAKE_CURRENT_SOURCE_DIR}/include")
message("[INFO] PROJECT_BINARY_DIR= ${PROJECT_BINARY_DIR}")

add_library(str_util_static STATIC src/str_util.cc)
set_target_properties(str_util_static PROPERTIES OUTPUT_NAME "str_util")

target_include_directories(str_util_static PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
#target_include_directories(str_util_static PUBLIC
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#)
