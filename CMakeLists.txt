cmake_minimum_required(VERSION 3.29)
project(Final)

set(CMAKE_CXX_STANDARD 20)

add_executable(Final main.cpp
        Student.cpp
        Student.h
        StudentManager.cpp
        StudentManager.h
)
