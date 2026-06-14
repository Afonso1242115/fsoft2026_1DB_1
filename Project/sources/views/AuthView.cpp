#include "AuthView.h"#include "AuthView.h"
#include <iostream>

std::string AuthView::readString(const std::string& message) const {
    std::string value;
    std::cout << message;
    std::getline(std::cin, value);
    return value;
}

void AuthView::showRegisterHeader() const {
    std::cout << "\n----------------------------------------------\n";
    std::cout << "Register Account\n";
    std::cout << "----------------------------------------------\n";
}

void AuthView::showLoginHeader() const {
    std::cout << "\n----------------------------------------------\n";
    std::cout << "Login\n";
    std::cout << "----------------------------------------------\n";
}

std::string AuthView::askName() const { return readString("Name: "); }
std::string AuthView::askEmail() const { return readString("Email: "); }
std::string AuthView::askPassword() const { return readString("Password: "); }
void AuthView::showInvalidName() const { std::cout << "Name must have at least 3 characters.\n"; }
void AuthView::showInvalidEmail() const { std::cout << "Email must contain @ and .\n"; }
void AuthView::showInvalidPassword() const {
    std::cout << "Password must have at least 8 characters, one uppercase letter, one lowercase letter and one number.\n";
}
void AuthView::showRegisterSuccess() const { std::cout << "Account created successfully.\n"; }
void AuthView::showLoginSuccess(const UserDTO& user) const { std::cout << "Welcome back, " << user.name << "!\n"; }
