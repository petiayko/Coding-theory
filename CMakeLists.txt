cmake_minimum_required(VERSION 3.27)
project(Coding_theory)

set(CMAKE_CXX_STANDARD 20)

add_executable(Coding_theory main.cpp
        shannon_fano.cpp
        shannon_fano.hpp
        haffman.cpp
        haffman.hpp
        binary_tree.cpp
        binary_tree.hpp)
