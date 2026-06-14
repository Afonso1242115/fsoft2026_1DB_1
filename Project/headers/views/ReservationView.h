#ifndef RESERVATIONVIEW_H
#define RESERVATIONVIEW_H

#include <string>
#include <vector>
#include "Movie.h"
#include "Session.h"
#include "Seat.h"


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

    void showSessions(const std::vector<Session>& sessions) const;
    int askSessionId() const;
    void showSelectedSession(const Session* session) const;

    int askTicketQuantity() const;
    std::string askSeatCode(int seatNumber) const;

    void showSeats(const std::vector<Seat>& seats,
                   const std::vector<std::string>& selectedSeats) const;

    void showSelectedSeats(const std::vector<std::string>& selectedSeats) const;
    void showSeatSelected(const std::string& seatCode) const;
    void showSeatUnavailable() const;
};

#endif