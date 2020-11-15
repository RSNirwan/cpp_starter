cmake_minimum_required(VERSION 3.17)

project(cpp_starter CXX)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(lib/googletest)
add_subdirectory(src)
add_subdirectory(tests)