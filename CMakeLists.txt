CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(code17)

#include 
include_directories(${PROJECT_SOURCE_DIR}/${PROJECT_NAME})

# src
add_subdirectory(./src)
aux_source_directory(./src SRC_DIR)
add_executable(${PROJECT_NAME} ${SRC_DIR})
target_link_libraries(${PROJECT_NAME} src_lib)

#
include(CTest)
enable_testing()

macro (do_test arg1 result)
  add_test (test_${arg1} ${PROJECT_NAME} ${arg1})
  set_tests_properties (test_${arg1}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

do_test("III" 3)
do_test("IV" 4)
do_test("IX" 9)
do_test("LVIII" 58)
do_test("MCMXCIV" 1994)