cmake_minimum_required(VERSION 4.1)
project(MovieTicketSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(MovieTicketSystem
        main.cpp

        sources/controllers/MainController.cpp
        sources/controllers/AuthController.cpp
        sources/controllers/ReservationController.cpp

        sources/views/MainView.cpp
        sources/views/AuthView.cpp
        sources/views/ReservationView.cpp

        sources/model/User.cpp
        sources/model/Movie.cpp
        sources/model/Session.cpp
        sources/model/Seat.cpp
        sources/model/Ticket.cpp
        sources/model/Payment.cpp
        sources/model/Reservation.cpp

        sources/mapper/UserMapper.cpp
        sources/mapper/MovieMapper.cpp
        sources/mapper/SessionMapper.cpp
        sources/mapper/SeatMapper.cpp
        sources/mapper/ReservationMapper.cpp

        sources/repository/MovieTicketRepositoryMemory.cpp

        sources/services/AuthService.cpp
        sources/services/ReservationService.cpp
        headers/repository/MovieTicketRepositoryMemory.h


)

target_include_directories(MovieTicketSystem PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/controllers
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/views
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/model
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/exceptions
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/dto
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/mapper
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/repository
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/services
)
