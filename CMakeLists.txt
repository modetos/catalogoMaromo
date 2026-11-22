cmake_minimum_required(VERSION 4.1)
project(catalogo C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(catalogo
        main.c
        modulo.c
        modulo.h)
