#include "../../headers/controllers/AuthController.h"

AuthController::AuthController(UserContainer& userContainer)
    : userContainer(userContainer) {
}

void AuthController::registerUser() {
    std::string name;
    std::string email;
    std::string password;

    view.showRegisterHeader();

    while (true) {
        name = view.askName();

        if (User::isNameValid(name)) {
            break;
        }

        view.showInvalidName();
    }

    while (true) {
        email = view.askEmail();

        if (User::isEmailValid(email)) {
            break;
        }

        view.showInvalidEmail();
    }

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