#ifndef RESERVATIONVIEW_H
#define RESERVATIONVIEW_H

#include <string>
#include <vector>
#include "../model/Session.h"
#include "../model/Reservation.h"

class ReservationView {
private:
    int readInt(const std::string& message) const;
    std::string readString(const std::string& message) const;

public:
    void showHeader(const std::string& title) const;

    int askMovieId() const;
    int askSessionId() const;
    int askTicketQuantity() const;
    std::string askSeatCode(int seatNumber) const;
    int askTicketType(double basePrice) const;
    int askPaymentMethod(double amount) const;

    void showSelectedSeats(const std::vector<std::string>& selectedSeats) const;
    void showSeatSelected(const std::string& seatCode) const;
    void showSeatUnavailable() const;
    void showPaymentApproved() const;
    void showReservationSuccess(const Reservation* reservation) const;
};

#endif