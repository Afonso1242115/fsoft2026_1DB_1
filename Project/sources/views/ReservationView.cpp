#include "ReservationView.h"
#include <iostream>
#include <limits>

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