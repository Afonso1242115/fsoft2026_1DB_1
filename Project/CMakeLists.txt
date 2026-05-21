cmake_minimum_required(VERSION 4.1)
project(MovieTicketSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(MovieTicketSystem
        main.cpp

        sources/controllers/AuthController.cpp
        sources/controllers/MainController.cpp
        sources/controllers/ReservationController.cpp

        sources/model/Cinema.cpp
        sources/model/Movie.cpp
        sources/model/Payment.cpp
        sources/model/Reservation.cpp
        sources/model/Seat.cpp
        sources/model/Session.cpp
        sources/model/Ticket.cpp
        sources/model/User.cpp

        sources/views/authViews.cpp
        sources/views/ReservationView.cpp
)

target_include_directories(MovieTicketSystem PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/controllers
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/model
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/views
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/exceptions
)