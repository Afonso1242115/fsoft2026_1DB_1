#include "MainView.h"
#include <iostream>
#include <limits>

void MainView::printLine(char symbol) const {
    std::cout << std::string(46, symbol) << '\n';
}

int MainView::readInt(const std::string& message) const {
    int value;

    while (true) {
        std::cout << message;

        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid number.\n";
    }
}

void MainView::showWelcome() const {
    printLine('=');
    std::cout << "|                                            |\n";
    std::cout << "|        WELCOME TO LETI CINEMA              |\n";
    std::cout << "|                                            |\n";
    std::cout << "|                                            |\n";
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
    showHeader("Main Menu");
    std::cout << "1 - Register\n";
    std::cout << "2 - Login\n";
    std::cout << "0 - Exit\n";

    return readInt("Option: ");
}

int MainView::askUserMenuOption() const {
    showHeader("User Menu");
    std::cout << "1 - Reservation screen\n";
    std::cout << "2 - Ticket screen\n";
    std::cout << "3 - Logout\n";

    return readInt("Option: ");
}

void MainView::showInvalidOption() const {
    std::cout << "Invalid option.\n";
}

void MainView::showLogoutMessage() const {
    std::cout << "Logged out. See you soon.\n";
}

void MainView::showGoodbye() const {
    std::cout << "Goodbye.\n";
}

void MainView::showError(const std::string& message) const {
    std::cout << "Error: " << message << "\n";
}
