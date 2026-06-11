#include "ReservationController.h"
#include "Exceptions.h"

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

Session* ReservationController::selectSession(Movie* movie) {
    std::vector<Session> sessions = cinema.getSessionsByMovie(movie->getId());

    if (sessions.empty()) {
        throw NotFoundException("No sessions found for this movie");
    }

    reservationView.showSessions(sessions);

    int sessionId = reservationView.askSessionId();

    Session* session = cinema.getSessionById(sessionId);

    if (session->getMovieId() != movie->getId()) {
        throw InvalidDataException("This session does not belong to the selected movie");
    }

    reservationView.showSelectedSession(session);

    return session;
}

void ReservationController::makeReservation(User* loggedUser) {
    reservationView.showReservationHeader();

    if (loggedUser == nullptr) {
        reservationView.showMessage("You must be logged in to make a reservation.");
        return;
    }

    Movie* movie = selectMovie();

    Session* session = selectSession(movie);


}

void ReservationController::viewMyReservations(User* loggedUser) const {
    reservationView.showMyReservationsHeader();

    cinema.listReservationsByUser(loggedUser);
}