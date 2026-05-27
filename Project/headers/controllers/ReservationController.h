#ifndef RESERVATIONCONTROLLER_H
#define RESERVATIONCONTROLLER_H

#include "Cinema.h"
#include "User.h"
#include "ReservationView.h"

class ReservationController {
private:
    Cinema& cinema;
    ReservationView reservationView;

public:
    ReservationController(Cinema& cinema);

    void makeReservation(User* loggedUser);
    void viewMyReservations(User* loggedUser) const;
};

#endif