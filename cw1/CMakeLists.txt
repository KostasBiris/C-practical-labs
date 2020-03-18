cmake_minimum_required(VERSION 2.8.12.2)

project(library C)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-std=c99 -DNDEBUG -fdump-rtl-expand")

include_directories(unity/include)

add_executable(users book_management users book_management.c users.c)

#add_executable(unit_tests unit_tests.c book_management.c unity/unity.c)

#install(TARGETS library RUNTIME DESTINATION bin)

