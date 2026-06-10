#ifndef RESERVATIONVIEW_H
#define RESERVATIONVIEW_H

#include <string>
#include <vector>
#include "Movie.h"

class ReservationView {
private:
    int readInt(const std::string& message) const;

public:
    void showReservationHeader() const;
    void showMyReservationsHeader() const;
    void showMessage(const std::string& message) const;

    void showMovies(const std::vector<Movie>& movies) const;
    int askMovieId() const;
    void showSelectedMovie(const Movie* movie) const;
};

#endif