#ifndef RESERVATIONVIEW_H
#define RESERVATIONVIEW_H

#include <string>

class ReservationView {
public:
    void showReservationHeader() const;
    void showMyReservationsHeader() const;
    void showMessage(const std::string& message) const;
};

#endif