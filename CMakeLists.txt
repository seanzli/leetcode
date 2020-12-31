CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(code10)

#include 
include_directories(${PROJECT_SOURCE_DIR}/code10)

# src
add_subdirectory(./src)
aux_source_directory(./src SRC_DIR)
add_executable(${PROJECT_NAME} ${SRC_DIR})
target_link_libraries(${PROJECT_NAME} src_lib)

#
enable_testing()

macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} code10 ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

do_test("aa" "a" 0)
do_test("aa" "a*" 1)
do_test("ab" ".*" 1)
do_test("aab" "c*a*b" 1)
do_test("mississippi" "mis*is*p*." 0)