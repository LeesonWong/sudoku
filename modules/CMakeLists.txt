file(GLOB_RECURSE SUDOKU_MODULES ./ *.cpp)

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(modules ${SUDOKU_MODULES})