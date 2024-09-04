file(GLOB_RECURSE SUDOKU_SOURCES "./*.cpp")

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR})

add_library(impl ${SUDOKU_SOURCES})