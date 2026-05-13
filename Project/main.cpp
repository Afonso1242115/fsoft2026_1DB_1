#include "User.h"
#include <iostream>
#include <exception>

int main() {
    try {
        //teste
        User user(1, "Afonso", "afonso@email.com", "Password1");

        std::cout << "User created successfully!\n";
        std::cout << "Name: " << user.getName() << "\n";
        std::cout << "Email: " << user.getEmail() << "\n";

        if (user.checkPassword("Password1")) {
            std::cout << "Password is correct.\n";
        } else {
            std::cout << "Password is incorrect.\n";
        }

    } catch (const std::exception& exception) {
        std::cout << "Error: " << exception.what() << "\n";
    }

    return 0;
}