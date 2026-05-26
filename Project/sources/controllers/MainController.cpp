#include "MainController.h"
#include <exception>

MainController::MainController()
    : loggedUser(nullptr),
      authController(userContainer),
      reservationController(cinema) {
    cinema.seedData();
}

void MainController::run() {
    mainView.showWelcome();
    mainMenu();
}

void MainController::mainMenu() {
    int option = 0;

    do {
        option = mainView.askMainMenuOption();

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
                    mainView.showGoodbye();
                    break;

                default:
                    mainView.showInvalidOption();
                    break;
            }
        } catch (const std::exception& exception) {
            mainView.showError(exception.what());
        }

    } while (option != 0);
}

void MainController::authenticatedMenu() {
    int option = 0;

    do {
        option = mainView.askAuthenticatedMenuOption();

        try {
            switch (option) {
                case 1:
                    reservationController.makeReservation(loggedUser);
                    break;

                case 2:
                    reservationController.viewMyReservations(loggedUser);
                    break;

                case 3:
                    loggedUser = nullptr;
                    mainView.showLogoutMessage();
                    break;

                default:
                    mainView.showInvalidOption();
                    break;
            }
        } catch (const std::exception& exception) {
            mainView.showError(exception.what());
        }

    } while (loggedUser != nullptr);
}