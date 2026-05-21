#include "../../headers/view/MainView.h"
#include <iostream>
#include <limits>

void MainView::printLine(char symbol) const {
    std::cout << std::string(46, symbol) << '\n';
}

void MainView::showWelcome() const {
    printLine('=');
    std::cout << "|                                            |\n";
    std::cout << "|        WELCOME TO CR7 CINEMA               |\n";
    std::cout << "|                                            |\n";
    std::cout << "|      Book movies, seats and tickets        |\n";
    std::cout << "|              in one place                  |\n";
    std::cout << "|                                            |\n";
    printLine('=');
}

void MainView::showHeader(const std::string& title) const {
    std::cout << '\n';
    printLine('-');
    std::cout << title << '\n';
    printLine('-');
}

int MainView::askMainMenuOption() const {
    int option;

    showHeader("Main Menu");
    std::cout << "1 - Register\n";
    std::cout << "2 - Login\n";
    std::cout << "0 - Exit\n";

    while (true) {
        std::cout << "Option: ";

        if (std::cin >> option) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return option;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid number.\n";
    }
}

int MainView::askAuthenticatedMenuOption() const {
    int option;

    showHeader("Movie Ticket Reservation");
    std::cout << "1 - Make reservation\n";
    std::cout << "2 - View my reservations\n";
    std::cout << "3 - Logout\n";

    while (true) {
        std::cout << "Option: ";

        if (std::cin >> option) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return option;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid number.\n";
    }
}

void MainView::showInvalidOption() const {
    std::cout << "Invalid option.\n";
}

void MainView::showGoodbye() const {
    std::cout << "Goodbye.\n";
}

void MainView::showLogoutMessage() const {
    std::cout << "Logged out. See you soon.\n";
}

void MainView::showError(const std::string& message) const {
    std::cout << "Error: " << message << "\n";
}