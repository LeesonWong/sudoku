cmake_minimum_required(VERSION 3.28)
project(sudoku)

set(CMAKE_CXX_STANDARD 17)

message("CMAKE_PROJECT_NAME ${CMAKE_PROJECT_NAME}")
message("PROJECT_NAME ${PROJECT_NAME}")

add_executable(${CMAKE_PROJECT_NAME} main.cpp)