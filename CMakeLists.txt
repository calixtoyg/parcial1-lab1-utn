cmake_minimum_required(VERSION 3.12)
project(Gonzalez_Calixto_1F C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Gonzalez_Calixto_1F
        alquiler.c
        alquiler.h
        cliente.c
        cliente.h
        functionsForProjects.c
        functionsForProjects.h
        juego.c
        juego.h
        main.c)
