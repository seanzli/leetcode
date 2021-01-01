CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(code5)

#include 
include_directories(${PROJECT_SOURCE_DIR}/code5)

# src
add_subdirectory(./src)
aux_source_directory(./src SRC_DIR)
add_executable(${PROJECT_NAME} ${SRC_DIR})
target_link_libraries(${PROJECT_NAME} src_lib)

#
enable_testing()

macro (do_test arg1 result)
  add_test (test_${arg1} code5 ${arg1} )
  set_tests_properties (test_${arg1}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

#do_test("abc" "false")
do_test("aba" "aba")
do_test("a" "a")