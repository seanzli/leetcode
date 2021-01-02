CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(code6)

#include 
include_directories(${PROJECT_SOURCE_DIR}/code6)

# src
add_subdirectory(./src)
aux_source_directory(./src SRC_DIR)
add_executable(${PROJECT_NAME} ${SRC_DIR})
target_link_libraries(${PROJECT_NAME} src_lib)

#
include(CTest)
enable_testing()

macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} code6 ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

#do_test("abc" "false")
do_test("A" 3 "A")
do_test("PAYPALISHIRING" 3 "PAHNAPLSIIGYIR")
do_test("PAYPALISHIRING" 4 "PINALSIGYAHRPI")