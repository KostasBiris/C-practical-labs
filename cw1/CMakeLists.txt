cmake_minimum_required(VERSION 2.8.12.2)

project(restaurant C)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-fdump-rtl-expand")

include_directories(unity/include)

add_executable(restaurant main.c interface.c customer.c order.c)

add_executable(unit_tests unit_tests.c order.c unity/src/unity.c)

install(TARGETS restaurant RUNTIME DESTINATION bin)

