cmake_minimum_required(VERSION 3.12)

project(bf-transpiler)

add_executable(bfuck src/bft.cpp src/logger.cpp src/parser.cpp)

enable_testing()

file(GLOB test_files "example/*.txt")
foreach(file ${test_files})
  get_filename_component(bare_file ${file} NAME)
  add_test("test_${bare_file}" ./test.sh ${file})
endforeach()
