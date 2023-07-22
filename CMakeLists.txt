cmake_minimum_required(VERSION 3.25)
project(menuapp)

set(CMAKE_CXX_STANDARD 20)

add_executable(menuapp main.cpp Food.h List.h clear_screen.h List.cpp clear_screen.cpp authentication.cpp authentication.h Drink.h)
