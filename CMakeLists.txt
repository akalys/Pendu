cmake_minimum_required(VERSION 3.10)  # Spécifiez la version minimale de CMake

# Définissez le nom du projet et la version
project(Pendu VERSION 1.0)

# Spécifiez la norme C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajoutez les fichiers source à votre projet pour créer un exécutable
add_executable(pjpendu pjpendu.cpp humain.cpp machine.cpp joueur.cpp jeuPendu.cpp pendaison.cpp)
