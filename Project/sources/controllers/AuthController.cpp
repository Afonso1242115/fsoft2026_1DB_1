#include "AuthController.h"

AuthController::AuthController(UserContainer& userContainer)
    : userContainer(userContainer) {
}

void AuthController::registerUser() {
    std::string name;
    std::string email;
    std::string password;

    view.showRegisterHeader();

    // Stay in this loop until the name is valid.
    while (true) {
        name = view.askName();

        if (User::isNameValid(name)) {
            break;
        }

        view.showInvalidName();
    }

    // Stay in this loop until the email is valid.
    while (true) {
        email = view.askEmail();

        if (User::isEmailValid(email)) {
            break;
        }

        view.showInvalidEmail();
    }

    // Stay in this loop until the password is valid.
    while (true) {
        password = view.askPassword();

        if (User::isPasswordValid(password)) {
            break;
        }

        view.showInvalidPassword();
    }

    userContainer.add(name, email, password);
    view.showRegisterSuccess();
}

User* AuthController::loginUser() {
    view.showLoginHeader();

    std::string email = view.askEmail();
    std::string password = view.askPassword();

    User* user = userContainer.login(email, password);
    view.showLoginSuccess(user);

    return user;
}
