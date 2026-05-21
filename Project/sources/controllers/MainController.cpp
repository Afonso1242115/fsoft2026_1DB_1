#include "../../headers/controllers/MainController.h"

MainController::MainController()
    : loggedUser(nullptr),
      authController(userContainer),
      reservationController(cinema) {
    cinema.seedData();
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

                    if (loggedUser != nullptr) {
                        authenticatedMenu();
                    }

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

void MainController::authenticatedMenu() {
    int option = 0;

    do {
        option = view.askAuthenticatedMenuOption();

        try {
            switch (option) {
                case 1:
                    reservationController.makeReservation(loggedUser);
                    break;

                case 2:
                    reservationController.showUserReservations(loggedUser);
                    break;

                case 3:
                    loggedUser = nullptr;
                    view.showLogoutMessage();
                    break;

                default:
                    view.showInvalidOption();
                    break;
            }
        } catch (const std::exception& exception) {
            view.showError(exception.what());
        }

    } while (loggedUser != nullptr);
}

void MainController::run() {
    view.showWelcome();
    mainMenu();
}
