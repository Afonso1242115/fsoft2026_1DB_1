#include "ReservationView.h"
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

void ReservationView::showMessage(const std::string& message) const { std::cout << message << "\n"; }

void ReservationView::showMovies(const std::vector<MovieDTO>& movies) const {
    std::cout << "\nAvailable movies:\n";
    for (const MovieDTO& movie : movies) {
        std::cout << movie.id << " - " << movie.title << " | " << movie.genre << " | " << movie.durationMinutes << " min\n";
    }
}

int ReservationView::askMovieId() const { return readInt("Choose movie id: "); }

void ReservationView::showSelectedMovie(const MovieDTO& movie) const {
    std::cout << "\nSelected movie: " << movie.title << " (" << movie.genre << ", " << movie.durationMinutes << " min)\n";
}

void ReservationView::showSessions(const std::vector<SessionDTO>& sessions) const {
    std::cout << "\nAvailable sessions:\n";
    for (const SessionDTO& session : sessions) {
        std::cout << session.id << " - " << session.time << " | " << session.room << " | EUR "
                  << std::fixed << std::setprecision(2) << session.basePrice << "\n";
    }
}

int ReservationView::askSessionId() const { return readInt("Choose session id: "); }

void ReservationView::showSelectedSession(const SessionDTO& session) const {
    std::cout << "\nSelected session: " << session.time << " | " << session.room << " | EUR "
              << std::fixed << std::setprecision(2) << session.basePrice << "\n";
}

int ReservationView::askTicketQuantity() const { return readInt("How many tickets do you want? "); }

std::string ReservationView::askSeatCode(int seatNumber) const {
    std::string seatCode;
    std::cout << "Choose seat " << seatNumber << ": ";
    std::getline(std::cin, seatCode);
    return seatCode;
}

void ReservationView::showSeats(const std::vector<SeatDTO>& seats, const std::vector<std::string>& selectedSeats) const {
    std::cout << "\nSeat map:\n";
    int count = 0;
    for (const SeatDTO& seat : seats) {
        bool selected = false;
        for (const std::string& selectedSeat : selectedSeats) {
            if (selectedSeat == seat.code) selected = true;
        }
        if (seat.reserved) std::cout << "[XX] ";
        else if (selected) std::cout << "[**] ";
        else std::cout << "[" << seat.code << "] ";
        count++;
        if (count % 4 == 0) std::cout << "\n";
    }
}

void ReservationView::showSelectedSeats(const std::vector<std::string>& selectedSeats) const {
    std::cout << "\nSelected seats: ";
    if (selectedSeats.empty()) std::cout << "none";
    else for (const std::string& seat : selectedSeats) std::cout << seat << " ";
    std::cout << "\n";
}

void ReservationView::showSeatSelected(const std::string& seatCode) const { std::cout << "Seat " << seatCode << " selected.\n"; }
void ReservationView::showSeatUnavailable() const { std::cout << "That seat is already selected, reserved, or does not exist.\n"; }

int ReservationView::askTicketType(double basePrice) const {
    std::cout << "\n----------------------------------------------\n";
    std::cout << "Ticket Type\n";
    std::cout << "----------------------------------------------\n";
    std::cout << "1 - Normal  | EUR " << std::fixed << std::setprecision(2) << basePrice << "\n";
    std::cout << "2 - Student | EUR " << std::fixed << std::setprecision(2) << basePrice * 0.80 << "\n";
    std::cout << "3 - Senior  | EUR " << std::fixed << std::setprecision(2) << basePrice * 0.70 << "\n";
    return readInt("Option: ");
}

int ReservationView::askPaymentMethod(double amount) const {
    std::cout << "\n----------------------------------------------\n";
    std::cout << "Payment\n";
    std::cout << "----------------------------------------------\n";
    std::cout << "Total: EUR " << std::fixed << std::setprecision(2) << amount << "\n\n";
    std::cout << "1 - Card\n";
    std::cout << "2 - MBWay\n";
    std::cout << "3 - Cash\n";
    return readInt("Payment method: ");
}

void ReservationView::showPaymentApproved() const { std::cout << "Payment approved.\n"; }
void ReservationView::showReservationSuccess(const ReservationDTO& reservation) const {
    std::cout << "\nReservation #" << reservation.id << " created successfully.\n";
}

void ReservationView::showReservations(const std::vector<ReservationDTO>& reservations) const {
    if (reservations.empty()) {
        std::cout << "No reservations yet.\n";
        return;
    }
    for (const ReservationDTO& reservation : reservations) {
        std::cout << "Reservation #" << reservation.id << "\n";
        std::cout << "Movie: " << reservation.movieTitle << "\n";
        std::cout << "Session: " << reservation.sessionTime << " | " << reservation.room << "\n";
        std::cout << "Seats: ";
        for (const std::string& seat : reservation.seats) std::cout << seat << " ";
        std::cout << "\n";
        std::cout << "Ticket: " << reservation.ticketType << "\n";
        std::cout << "Payment: " << reservation.paymentMethod << " | EUR " << std::fixed << std::setprecision(2) << reservation.amount << "\n";
        std::cout << "----------------------------------------------\n";
    }
}