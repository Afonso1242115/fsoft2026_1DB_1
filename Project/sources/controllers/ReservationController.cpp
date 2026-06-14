#include "ReservationController.h"
#include "Exceptions.h"
#include <cctype>
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

    int ticketQuantity = selectTicketQuantity();

    std::vector<std::string> selectedSeats = selectSeats(session, ticketQuantity);

    reservationView.showMessage("Next step: select ticket type and payment.");
}

void ReservationController::viewMyReservations(User* loggedUser) const {
    reservationView.showMyReservationsHeader();

    cinema.listReservationsByUser(loggedUser);
}

std::string ReservationController::formatSeatCode(const std::string& seatCode) const {
    std::string formatted;

    for (char character : seatCode) {
        if (!std::isspace(static_cast<unsigned char>(character))) {
            formatted += static_cast<char>(
                std::toupper(static_cast<unsigned char>(character))
            );
        }
    }

    return formatted;
}

int ReservationController::selectTicketQuantity() const {
    int quantity = reservationView.askTicketQuantity();

    if (quantity < 1 || quantity > 8) {
        throw InvalidDataException("Ticket quantity must be between 1 and 8");
    }

    return quantity;
}

std::vector<std::string> ReservationController::selectSeats(Session* session,
                                                            int ticketQuantity) const {
    std::vector<std::string> selectedSeats;

    while (static_cast<int>(selectedSeats.size()) < ticketQuantity) {
        reservationView.showSeats(session->getSeats(), selectedSeats);
        reservationView.showSelectedSeats(selectedSeats);

        std::string seatCode = formatSeatCode(
            reservationView.askSeatCode(static_cast<int>(selectedSeats.size()) + 1)
        );

        if (session->isSeatAvailable(seatCode, selectedSeats)) {
            selectedSeats.push_back(seatCode);
            reservationView.showSeatSelected(seatCode);
        } else {
            reservationView.showSeatUnavailable();
        }
    }

    reservationView.showSeats(session->getSeats(), selectedSeats);

    return selectedSeats;
}
