cmake_minimum_required (VERSION 2.8.9)

project (Ordenamiento)

include_directories(include)
set (SOURCES src/Ordenamiento.cpp src/main.cpp)
add_executable(Ordenamiento ${SOURCES})
