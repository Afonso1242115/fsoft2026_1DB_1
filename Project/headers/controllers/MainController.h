#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "MovieTicketRepositoryMemory.h"
#include "AuthService.h"
#include "ReservationService.h"
#include "MainView.h"
#include "AuthController.h"
#include "ReservationController.h"
#include "UserDTO.h"

class MainController {
private:
    MovieTicketRepositoryMemory repository;
    AuthService authService;
    ReservationService reservationService;

    MainView mainView;
    AuthController authController;
    ReservationController reservationController;

    bool loggedIn;
    UserDTO loggedUser;

    void mainMenu();
    void authenticatedMenu();

public:
    MainController();
    void run();
};

#endif
