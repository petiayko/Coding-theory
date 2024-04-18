cmake_minimum_required(VERSION 3.27)
project(Coding_theory)

set(CMAKE_CXX_STANDARD 20)

add_executable(Coding_theory main.cpp
        source/shannon_fano.cpp
        include/shannon_fano.hpp
        source/haffman.cpp
        include/haffman.hpp
)
