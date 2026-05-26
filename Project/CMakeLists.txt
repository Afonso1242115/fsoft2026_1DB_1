cmake_minimum_required(VERSION 4.1)
project(MovieTicketSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(MovieTicketSystem
        main.cpp

        sources/controllers/MainController.cpp
        sources/controllers/AuthController.cpp

        sources/views/MainView.cpp
        sources/views/AuthView.cpp

        sources/model/User.cpp
        sources/model/UserContainer.cpp
)

target_include_directories(MovieTicketSystem PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/controllers
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/views
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/model
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/exceptions
)
