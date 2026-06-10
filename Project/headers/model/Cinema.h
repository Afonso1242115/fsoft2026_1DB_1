#ifndef CINEMA_H
#define CINEMA_H

#include "User.h"
#include "Movie.h"
#include <vector>

class Cinema {
private:
    std::vector<Movie> movies;

public:
    Cinema();

    void seedData();

    const std::vector<Movie>& getMovies() const;
    Movie* getMovieById(int movieId);

    void listReservationsByUser(User* user) const;
};

#endif