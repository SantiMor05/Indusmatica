cmake_minimum_required(VERSION 3.31)
project(C__)

set(CMAKE_CXX_STANDARD 20)

add_executable(C__ main.cpp
        Persona.cpp
        Persona.h
        Conductor.cpp
        Conductor.h
        Automovil.cpp
        Automovil.h
        Cola.cpp
        Cola.h
        Nodo.cpp
        Nodo.h
        Infracciones.cpp
        Infracciones.h
        Multa.cpp
        Multa.h)
