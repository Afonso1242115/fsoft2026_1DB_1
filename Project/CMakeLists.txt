cmake_minimum_required(VERSION 4.1)
project(MovieTicketSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(MovieTicketSystem
        main.cpp
        sources/model/User.cpp
        headers/views/authView.h
        sources/Views/authViews.cpp
        headers/controllers/AuthController.h
        sources/controllers/AuthController.cpp
        headers/views/reservationView.h
        sources/views/ReservationView.cpp
        headers/controllers/ReservationController.h
        sources/controllers/ReservationController.cpp
        sources/controllers/MainController.cpp
)

target_include_directories(MovieTicketSystem PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/model
)