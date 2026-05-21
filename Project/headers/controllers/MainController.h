#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "../model/Cinema.h"

#include "../model/User.h"
#include "../views/MainView.h"
#include "AuthController.h"
#include "ReservationController.h"

class MainController {
private:
    Cinema cinema;
    UserContainer userContainer;
    User* loggedUser;

    MainView view;
    AuthController authController;
    ReservationController reservationController;

    void mainMenu();
    void authenticatedMenu();

public:
    MainController();

    void run();
};

#endif
