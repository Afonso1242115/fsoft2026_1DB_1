#include "MainController.h"
#include <exception>

MainController::MainController()
    : loggedUser(nullptr),
      authController(userContainer) {
}

void MainController::mainMenu() {
    int option = 0;

    do {
        option = view.askMainMenuOption();

        try {
            switch (option) {
                case 1:
                    authController.registerUser();
                    break;

                case 2:
                    loggedUser = authController.loginUser();
                    userMenu();
                    break;

                case 0:
                    view.showGoodbye();
                    break;

                default:
                    view.showInvalidOption();
                    break;
            }
        } catch (const std::exception& exception) {
            view.showError(exception.what());
        }

    } while (option != 0);
}

void MainController::userMenu() {
    int option = 0;

    do {
        option = view.askUserMenuOption();

        switch (option) {
            case 1:
                view.showHeader("Reservation Screen");

                break;

            case 2:
                view.showHeader("Ticket Screen");

                break;

            case 3:
                loggedUser = nullptr;
                view.showLogoutMessage();
                break;

            default:
                view.showInvalidOption();
                break;
        }

    } while (loggedUser != nullptr);
}

void MainController::run() {
    view.showWelcome();
    mainMenu();
}
