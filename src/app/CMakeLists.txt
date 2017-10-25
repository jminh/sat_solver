#message("[INFO] CMAKE_CURRENT_SOURCE_DIR= ${CMAKE_CURRENT_SOURCE_DIR}")
#message("[INFO] PROJECT_BINARY_DIR= ${PROJECT_BINARY_DIR}")

add_library(sat_static STATIC sat.cc)
target_link_libraries(sat_static str_util_static)
set_target_properties(sat_static PROPERTIES OUTPUT_NAME "sat")
#target_include_directories(sat_static
#  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main main.cc)
target_link_libraries(main sat_static str_util_static)
