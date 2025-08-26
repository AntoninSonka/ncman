cmake_minimum_required(VERSION 3.10)
project(ncman)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(ncman ${SOURCES})

target_link_libraries(ncman ${CURSES_LIBRARIES})
