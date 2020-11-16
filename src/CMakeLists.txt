cmake_minimum_required(VERSION 3.17)

set(Headers 
    Module1.hpp
)
set(Sources 
    Module1.cpp
)

add_library(m1 STATIC ${Sources} ${Headers})
target_include_directories(m1 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")


#following only needed if main.cpp need to be compiled
add_executable(main main.cpp)
target_link_libraries(main PUBLIC m1)