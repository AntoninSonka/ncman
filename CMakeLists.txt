cmake_minimum_required(VERSION 3.10)
project(ncman)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(main ${SOURCES})
