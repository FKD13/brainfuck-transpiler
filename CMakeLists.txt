project(bf-transpiler)

add_executable(bfuck src/bft.cpp src/logger.cpp src/parser.cpp)

enable_testing()

add_test(test ./bfuck example/test.txt)
