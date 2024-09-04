cmake_minimum_required(VERSION 3.28)
project(sudoku)

set(CMAKE_CXX_STANDARD 17)

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/impl/include)

add_subdirectory(impl)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)