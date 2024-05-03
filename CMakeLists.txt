cmake_minimum_required(VERSION 3.10)  

project(Pendu VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(pjpendu pjpendu.cpp humain.cpp machine.cpp joueur.cpp jeuPendu.cpp pendaison.cpp)
