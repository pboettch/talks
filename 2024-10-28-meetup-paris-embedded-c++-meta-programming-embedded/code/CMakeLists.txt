cmake_minimum_required(VERSION 3.25)

project(c++-embedded CXX)

add_library(compile_objects OBJECT
    start.cpp
    step-1.cpp
    step-2.cpp
    step-3.cpp
    step-4.cpp)


add_library(cpp OBJECT classic++.cpp)


add_library(final OBJECT
    c++/final.cpp)
target_compile_options(final PRIVATE --include=${CMAKE_CURRENT_SOURCE_DIR}/c++/product.h)
