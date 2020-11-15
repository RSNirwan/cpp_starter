cmake_minimum_required(VERSION 3.18)

set(Headers 
    Module1.h
)
set(Sources 
    Module1.cpp
)

add_library(m1 STATIC ${Sources} ${Headers})


#following only needed if main.cpp need to be compiled
add_executable(main main.cpp)
target_link_libraries(main PUBLIC m1)