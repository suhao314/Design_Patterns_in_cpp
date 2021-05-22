cmake_minimum_required(VERSION 3.0.0)
project(Visitor VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}")
set(CMAKE_C_COMPILER "gcc")
aux_source_directory(. DIR_SRCS)

add_executable(Visitor ${DIR_SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


