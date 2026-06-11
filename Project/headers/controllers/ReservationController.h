#ifndef RESERVATIONCONTROLLER_H
#define RESERVATIONCONTROLLER_H

#include "Cinema.h"
#include "User.h"
#include "Movie.h"
#include "Session.h"
#include "ReservationView.h"

class ReservationController {
private:
    Cinema& cinema;
    ReservationView reservationView;

    Movie* selectMovie();
    Session* selectSession(Movie* movie);

public:
    ReservationController(Cinema& cinema);

    void makeReservation(User* loggedUser);
    void viewMyReservations(User* loggedUser) const;
};

#endif