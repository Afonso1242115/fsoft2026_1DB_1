#ifndef RESERVATIONVIEW_H
#define RESERVATIONVIEW_H

#include "MovieDTO.h"
#include "SessionDTO.h"
#include "SeatDTO.h"
#include "ReservationDTO.h"
#include <string>
#include <vector>

class ReservationView {
private:
    int readInt(const std::string& message) const;

public:
    void showReservationHeader() const;
    void showMyReservationsHeader() const;
    void showMessage(const std::string& message) const;

    void showMovies(const std::vector<MovieDTO>& movies) const;
    int askMovieId() const;
    void showSelectedMovie(const MovieDTO& movie) const;

    void showSessions(const std::vector<SessionDTO>& sessions) const;
    int askSessionId() const;
    void showSelectedSession(const SessionDTO& session) const;

    int askTicketQuantity() const;
    std::string askSeatCode(int seatNumber) const;
    void showSeats(const std::vector<SeatDTO>& seats, const std::vector<std::string>& selectedSeats) const;
    void showSelectedSeats(const std::vector<std::string>& selectedSeats) const;
    void showSeatSelected(const std::string& seatCode) const;
    void showSeatUnavailable() const;

    int askTicketType(double basePrice) const;
    int askPaymentMethod(double amount) const;
    void showPaymentApproved() const;
    void showReservationSuccess(const ReservationDTO& reservation) const;
    void showReservations(const std::vector<ReservationDTO>& reservations) const;
};

#endif