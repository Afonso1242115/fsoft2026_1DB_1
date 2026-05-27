#include "ReservationView.h"
#include <iostream>

void ReservationView::showReservationHeader() const {
    std::cout << "\n----------------------------------------------\n";
    std::cout << "Make Reservation\n";
    std::cout << "----------------------------------------------\n";
}

void ReservationView::showMyReservationsHeader() const {
    std::cout << "\n----------------------------------------------\n";
    std::cout << "My Reservations\n";
    std::cout << "----------------------------------------------\n";
}

void ReservationView::showMessage(const std::string& message) const {
    std::cout << message << "\n";
}