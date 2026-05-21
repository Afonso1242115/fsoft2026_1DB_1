#include "../../headers/view/ReservationView.h"
#include <iostream>
#include <limits>
#include <iomanip>

int ReservationView::readInt(const std::string& message) const {
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

std::string ReservationView::readString(const std::string& message) const {
    std::string value;

    std::cout << message;
    std::getline(std::cin, value);

    return value;
}

void ReservationView::showHeader(const std::string& title) const {
    std::cout << "\n----------------------------------------------\n";
    std::cout << title << "\n";
    std::cout << "----------------------------------------------\n";
}

int ReservationView::askMovieId() const {
    return readInt("Choose movie id: ");
}

int ReservationView::askSessionId() const {
    return readInt("Choose session id: ");
}

int ReservationView::askTicketQuantity() const {
    return readInt("How many tickets do you want? ");
}

std::string ReservationView::askSeatCode(int seatNumber) const {
    return readString("Choose seat " + std::to_string(seatNumber) + ": ");
}

int ReservationView::askTicketType(double basePrice) const {
    showHeader("Ticket Type");

    std::cout << "1 - Normal  | EUR " << std::fixed << std::setprecision(2) << basePrice << "\n";
    std::cout << "2 - Student | EUR " << basePrice * 0.80 << "\n";
    std::cout << "3 - Senior  | EUR " << basePrice * 0.70 << "\n";

    return readInt("Option: ");
}

int ReservationView::askPaymentMethod(double amount) const {
    showHeader("Payment");

    std::cout << "Total: EUR " << std::fixed << std::setprecision(2) << amount << "\n\n";
    std::cout << "1 - Card\n";
    std::cout << "2 - MBWay\n";
    std::cout << "3 - Cash\n";

    return readInt("Payment method: ");
}

void ReservationView::showSelectedSeats(const std::vector<std::string>& selectedSeats) const {
    std::cout << "\nSelected seats: ";

    if (selectedSeats.empty()) {
        std::cout << "none";
    } else {
        for (const std::string& seatCode : selectedSeats) {
            std::cout << seatCode << " ";
        }
    }

    std::cout << "\n";
}

void ReservationView::showSeatSelected(const std::string& seatCode) const {
    std::cout << "Seat " << seatCode << " selected.\n";
}

void ReservationView::showSeatUnavailable() const {
    std::cout << "That seat is already selected or reserved. Choose another one.\n";
}

void ReservationView::showPaymentApproved() const {
    std::cout << "Payment approved.\n";
}

void ReservationView::showReservationSuccess(const Reservation* reservation) const {
    std::cout << "\nReservation #" << reservation->getId()
              << " created successfully.\n";
}