#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include "AuthService.h"
#include "AuthView.h"
#include "UserDTO.h"

class AuthController {
private:
    AuthService& authService;
    AuthView authView;

public:
    AuthController(AuthService& authService);

    void registerUser();
    UserDTO loginUser();
};

#endif