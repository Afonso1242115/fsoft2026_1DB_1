#include "ReservationController.h"

ReservationController::ReservationController(Cinema& cinema)
    : cinema(cinema) {
}

void ReservationController::makeReservation(User* loggedUser) {
    reservationView.showReservationHeader();

    if (loggedUser == nullptr) {
        reservationView.showMessage("You must be logged in to make a reservation.");
        return;
    }


}

void ReservationController::viewMyReservations(User* loggedUser) const {
    reservationView.showMyReservationsHeader();

    cinema.listReservationsByUser(loggedUser);
}   