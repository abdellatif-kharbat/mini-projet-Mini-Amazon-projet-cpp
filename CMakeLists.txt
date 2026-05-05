cmake_minimum_required(VERSION 3.10)

project(MiniAmazon)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(MiniAmazon
    src/main.cpp
    src/Produit.cpp
    src/Client.cpp
    src/Panier.cpp
    src/Commande.cpp
)
