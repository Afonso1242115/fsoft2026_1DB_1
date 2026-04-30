cmake_minimum_required(VERSION 4.1)
project(MovieTicketSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MovieTicketSystem
        main.cpp

        headers/model/user.h
        headers/model/administrator.h
        headers/model/movies.h
        headers/model/seat.h

        classes/model/user.cpp
        classes/model/administrator.cpp
        classes/model/movies.cpp
        classes/model/seat.cpp
)

target_include_directories(MovieTicketSystem PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/model
)