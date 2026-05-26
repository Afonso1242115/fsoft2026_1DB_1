#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include "UserContainer.h"
#include "AuthView.h"

class AuthController {
private:
    UserContainer& userContainer;
    AuthView view;

public:
    explicit AuthController(UserContainer& userContainer);

    void registerUser();
    User* loginUser();
};

#endif
