#include "Cinema.h"
#include "Exceptions.h"
#include <iostream>

Cinema::Cinema() {
}

void Cinema::seedData() {
    movies.push_back(Movie(1, "Interstellar", 169, "Sci-Fi"));
    movies.push_back(Movie(2, "Project Hail Mary", 156, "Sci-Fi"));
    movies.push_back(Movie(3, "The Notebook", 121, "Drama"));
}

const std::vector<Movie>& Cinema::getMovies() const {
    return movies;
}

Movie* Cinema::getMovieById(int movieId) {
    for (Movie& movie : movies) {
        if (movie == movieId) {
            return &movie;
        }
    }

    throw NotFoundException("Movie not found");
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