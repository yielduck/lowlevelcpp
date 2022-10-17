cmake_minimum_required(VERSION 3.0)
project(jopa)

add_executable(jopa main.cpp quadruple.cpp)
target_include_directories(jopa PUBLIC test)
