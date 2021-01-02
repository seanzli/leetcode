CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(code7)

#include 
include_directories(${PROJECT_SOURCE_DIR}/code7)

# src
add_subdirectory(./src)
aux_source_directory(./src SRC_DIR)
add_executable(${PROJECT_NAME} ${SRC_DIR})
target_link_libraries(${PROJECT_NAME} src_lib)

#
include(CTest)
enable_testing()

macro (do_test arg1 result)
  add_test (test_${arg1} code7 ${arg1} )
  set_tests_properties (test_${arg1}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

#do_test("abc" "false")
do_test(123  "321")
do_test(-123 "-321")
do_test(120  "21")
do_test(0  "0")
do_test(1534236469 "0")
do_test(-2147483648 "0")