#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "UserContainer.h"
#include "User.h"
#include "MainView.h"
#include "AuthController.h"

class MainController {
private:
    UserContainer userContainer;
    User* loggedUser;

    MainView view;
    AuthController authController;

    void mainMenu();
    void userMenu();

public:
    MainController();
    void run();
};

#endif
