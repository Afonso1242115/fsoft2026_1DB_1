#include "Cinema.h"
#include "Exceptions.h"
#include <iostream>

Cinema::Cinema() {
}

void Cinema::seedData() {
    movies.push_back(Movie(1, "Interstellar", 169, "Sci-Fi"));
    movies.push_back(Movie(2, "Spider-Man", 121, "Action"));
    movies.push_back(Movie(3, "The Batman", 176, "Crime"));

    sessions.push_back(Session(1, 1, "Room 1", "14:30", 7.50));
    sessions.push_back(Session(2, 1, "Room 2", "18:00", 8.00));
    sessions.push_back(Session(3, 2, "Room 1", "16:00", 7.00));
    sessions.push_back(Session(4, 2, "Room 3", "21:30", 8.50));
    sessions.push_back(Session(5, 3, "Room 2", "20:00", 8.00));
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

std::vector<Session> Cinema::getSessionsByMovie(int movieId) const {
    std::vector<Session> movieSessions;

    for (const Session& session : sessions) {
        if (session.getMovieId() == movieId) {
            movieSessions.push_back(session);
        }
    }

    return movieSessions;
}

Session* Cinema::getSessionById(int sessionId) {
    for (Session& session : sessions) {
        if (session == sessionId) {
            return &session;
        }
    }

    throw NotFoundException("Session not found");
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