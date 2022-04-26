cmake_minimum_required(VERSION 3.22)
project(Answersfor_luogu)

set(CMAKE_CXX_STANDARD 11)

add_executable(Answersfor_luogu main.cpp)

add_executable(T235196-Pai cpp/T235196-Pai.cpp)
add_executable(T235196 cpp/T235196.cpp cpp/T235196-Con.cpp)
add_executable(P1010 cpp/P1010.cpp)