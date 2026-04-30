cmake_minimum_required(VERSION 3.20)
project(MovieTicketSystem LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(MovieTicketSystem
        main.cpp
        classes/model/user.cpp
        classes/model/administrator.cpp
        classes/model/movies.cpp
        classes/model/seat.cpp
        headers/model/user.h
)