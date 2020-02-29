cmake_minimum_required(VERSION 2.8)

project(restaurant)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-fdump-rtl-expand")


add_executable(restaurant main.c interface.c customer.c order.c)


install(TARGETS restaurant RUNTIME DESTINATION bin)
