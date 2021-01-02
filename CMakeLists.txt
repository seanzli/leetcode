CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(code9)

#include 
include_directories(${PROJECT_SOURCE_DIR}/code9)

# src
add_subdirectory(./src)
aux_source_directory(./src SRC_DIR)
add_executable(${PROJECT_NAME} ${SRC_DIR})
target_link_libraries(${PROJECT_NAME} src_lib)

#
include(CTest)
enable_testing()

macro (do_test arg1 result)
  add_test (test_${arg1} code9 ${arg1})
  set_tests_properties (test_${arg1}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

#do_test("abc" "false")
do_test(121  "true")
do_test(-121 "false")
do_test(10 "false")
do_test(-101 "false")
do_test(1234567899 "false")