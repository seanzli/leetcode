CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(code64)

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

do_test("0" 1)
do_test(" 0.1 " 0)
do_test("abc" 0)
do_test("1 a" 0)
do_test("2e10" 1)
do_test(" -90e3" 1)
do_test(" 1e" 0)
do_test("e3" 0)
do_test(" 6e-1" 1)
do_test(" 99e2.5" 0)
do_test("53.5e93" 1)
do_test(" --6 " 0)
do_test("-+3" 0)
do_test("95a54e53" 0)