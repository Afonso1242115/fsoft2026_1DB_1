#include "MainController.h"
#include <exception>

MainController::MainController()
    : authService(repository),
      reservationService(repository),
      authController(authService),
      reservationController(reservationService) {
    loggedIn = false;
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
                    loggedIn = true;
                    authenticatedMenu();
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
                    reservationController.makeReservation(loggedUser.id);
                    break;

                case 2:
                    reservationController.viewMyReservations(loggedUser.id);
                    break;

                case 3:
                    loggedIn = false;
                    mainView.showLogoutMessage();
                    break;

                default:
                    mainView.showInvalidOption();
                    break;
            }
        } catch (const std::exception& exception) {
            mainView.showError(exception.what());
        }
    } while (loggedIn);
}
