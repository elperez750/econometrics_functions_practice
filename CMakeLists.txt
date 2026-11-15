cmake_minimum_required(VERSION 4.3)
project(econometrics_functions_practice C)

set(CMAKE_C_STANDARD 17)

add_executable(econometrics_functions_practice main.c
        required_structures.h
        loading_data.c
        loading_data.h)
