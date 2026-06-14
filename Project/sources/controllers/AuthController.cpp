#include "AuthController.h"
#include "User.h"

AuthController::AuthController(AuthService& authService)
    : authService(authService) {
}

void AuthController::registerUser() {
    authView.showRegisterHeader();

    std::string name;
    std::string email;
    std::string password;

    while (true) {
        name = authView.askName();
        if (User::isNameValid(name)) break;
        authView.showInvalidName();
    }

    while (true) {
        email = authView.askEmail();
        if (User::isEmailValid(email)) break;
        authView.showInvalidEmail();
    }

    while (true) {
        password = authView.askPassword();
        if (User::isPasswordValid(password)) break;
        authView.showInvalidPassword();
    }

    authService.registerUser(name, email, password);
    authView.showRegisterSuccess();
}

UserDTO AuthController::loginUser() {
    authView.showLoginHeader();

    std::string email = authView.askEmail();
    std::string password = authView.askPassword();

    UserDTO user = authService.login(email, password);
    authView.showLoginSuccess(user);

    return user;
}