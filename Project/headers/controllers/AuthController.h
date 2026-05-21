#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H


#include "../model/User.h"
#include "../views/AuthView.h"

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