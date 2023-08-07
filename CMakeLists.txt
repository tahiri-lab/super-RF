cmake_minimum_required(VERSION 3.25)
project(NewickBipartitionParser_)

set(CMAKE_CXX_STANDARD 17)

add_executable(NewickBipartitionParser_ main.cpp src/parser.cpp include/parser.hpp)
