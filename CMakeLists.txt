cmake_minimum_required(VERSION 3.8)
project(rw_lock)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(rw_lock ${SOURCE_FILES})