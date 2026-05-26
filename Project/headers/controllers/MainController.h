#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "User.h"
#include "UserContainer.h"
#include "Cinema.h"

#include "MainView.h"
#include "AuthController.h"
#include "ReservationController.h"

class MainController {
private:
    UserContainer userContainer;
    Cinema cinema;
    User* loggedUser;

    MainView mainView;
    AuthController authController;
    ReservationController reservationController;

    void mainMenu();
    void authenticatedMenu();

public:
    MainController();

    void run();
};

#endif