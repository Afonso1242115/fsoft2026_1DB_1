#include "Cinema.h"
#include <iostream>

Cinema::Cinema() {
}

void Cinema::seedData() {
    // function that will create movies, sessions and seats.

}

void Cinema::listReservationsByUser(User* user) const {
    if (user == nullptr) {
        std::cout << "No user is logged in.\n";
        return;
    }

    std::cout << "\n----------------------------------------------\n";
    std::cout << "Reservations for " << user->getName() << "\n";
    std::cout << "----------------------------------------------\n";
    std::cout << "No reservations yet.\n";
}