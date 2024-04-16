cmake_minimum_required(VERSION 3.27)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled1 main.cpp
        encryption.h
        encryption.cpp
        consoleWork.h
        fileWork.cpp
        fileWork.h
        fileView.h
        fileView.cpp
        Menu.h
        Menu.cpp
        consoleWork.cpp)
