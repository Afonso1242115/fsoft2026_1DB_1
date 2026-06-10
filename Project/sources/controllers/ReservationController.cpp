#include "ReservationController.h"

ReservationController::ReservationController(Cinema& cinema)
    : cinema(cinema) {
}

Movie* ReservationController::selectMovie() {
    reservationView.showMovies(cinema.getMovies());

    int movieId = reservationView.askMovieId();

    Movie* movie = cinema.getMovieById(movieId);

    reservationView.showSelectedMovie(movie);

    return movie;
}

void ReservationController::makeReservation(User* loggedUser) {
    reservationView.showReservationHeader();

    if (loggedUser == nullptr) {
        reservationView.showMessage("You must be logged in to make a reservation.");
        return;
    }

    Movie* movie = selectMovie();


}

void ReservationController::viewMyReservations(User* loggedUser) const {
    reservationView.showMyReservationsHeader();

    cinema.listReservationsByUser(loggedUser);
}