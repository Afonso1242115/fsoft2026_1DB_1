#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include "../model/UserContainer.h"
#include "../model/User.h"
#include "../view/AuthView.h"

class AuthController {
private:
    UserContainer& userContainer;
    AuthView view;

public:
    AuthController(UserContainer& userContainer);

    void registerUser();
    User* loginUser();
};

#endif