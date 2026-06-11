#ifndef CINEMA_H
#define CINEMA_H

#include "User.h"
#include "Movie.h"
#include "Session.h"
#include <vector>

class Cinema {
private:
    std::vector<Movie> movies;
    std::vector<Session> sessions;

public:
    Cinema();

    void seedData();

    const std::vector<Movie>& getMovies() const;
    Movie* getMovieById(int movieId);

    std::vector<Session> getSessionsByMovie(int movieId) const;
    Session* getSessionById(int sessionId);

    void listReservationsByUser(User* user) const;
};

#endif