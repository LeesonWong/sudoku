file(GLOB_RECURSE SUDOKU_SOURCES "src/*.cpp")


include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)

message("-----------------${SUDOKU_SOURCES}")

add_library(impl ${SUDOKU_SOURCES})