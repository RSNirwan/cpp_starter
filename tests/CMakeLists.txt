cmake_minimum_required(VERSION 3.18)

set(Projname m1test)

set(Sources 
    Module1Tests.cpp
)

add_executable(${Projname} ${Sources})

target_link_libraries(${Projname} PUBLIC 
    gtest_main
    m1
)

add_test(
    NAME ${Projname}
    COMMAND ${Projname}
)