#include "ReservationView.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include "Seat.h"

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

void ReservationView::showMessage(const std::string& message) const {
    std::cout << message << "\n";
}

void ReservationView::showMovies(const std::vector<Movie>& movies) const {
    std::cout << "\nAvailable movies:\n";

    for (const Movie& movie : movies) {
        std::cout << movie.getId() << " - "
                  << movie.getTitle()
                  << " | " << movie.getGenre()
                  << " | " << movie.getDurationMinutes()
                  << " min\n";
    }
}

int ReservationView::askMovieId() const {
    return readInt("Choose movie id: ");
}

void ReservationView::showSelectedMovie(const Movie* movie) const {
    if (movie == nullptr) {
        return;
    }

    std::cout << "\nSelected movie: "
              << movie->getTitle()
              << " (" << movie->getGenre() << ", "
              << movie->getDurationMinutes() << " min)\n";
}

void ReservationView::showSessions(const std::vector<Session>& sessions) const {
    std::cout << "\nAvailable sessions:\n";

    for (const Session& session : sessions) {
        std::cout << session.getId() << " - "
                  << session.getTime()
                  << " | " << session.getRoom()
                  << " | EUR " << std::fixed << std::setprecision(2)
                  << session.getBasePrice()
                  << "\n";
    }
}

int ReservationView::askSessionId() const {
    return readInt("Choose session id: ");
}

void ReservationView::showSelectedSession(const Session* session) const {
    if (session == nullptr) {
        return;
    }

    std::cout << "\nSelected session: "
              << session->getTime()
              << " | " << session->getRoom()
              << " | EUR " << std::fixed << std::setprecision(2)
              << session->getBasePrice()
              << "\n";
}
int ReservationView::askTicketQuantity() const {
    return readInt("How many tickets do you want? ");
}

std::string ReservationView::askSeatCode(int seatNumber) const {
    std::string seatCode;

    std::cout << "Choose seat " << seatNumber << ": ";
    std::getline(std::cin, seatCode);

    return seatCode;
}

void ReservationView::showSeats(const std::vector<Seat>& seats,
                                const std::vector<std::string>& selectedSeats) const {
    std::cout << "\nSeat map:\n";

    int count = 0;

    for (const Seat& seat : seats) {
        bool selected = false;

        for (const std::string& selectedSeat : selectedSeats) {
            if (selectedSeat == seat.getCode()) {
                selected = true;
            }
        }

        if (seat.isReserved()) {
            std::cout << "[XX] ";
        } else if (selected) {
            std::cout << "[**] ";
        } else {
            std::cout << "[" << seat.getCode() << "] ";
        }

        count++;

        if (count % 4 == 0) {
            std::cout << "\n";
        }
    }
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
    std::cout << "That seat is already selected, reserved, or does not exist.\n";
}
