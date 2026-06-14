#include "ReservationController.h"
#include "Exceptions.h"
#include <cctype>

ReservationController::ReservationController(ReservationService& reservationService)
    : reservationService(reservationService) {
}

MovieDTO ReservationController::selectMovie() {
    std::vector<MovieDTO> movies = reservationService.getMovies();
    reservationView.showMovies(movies);

    int movieId = reservationView.askMovieId();

    for (const MovieDTO& movie : movies) {
        if (movie.id == movieId) {
            reservationView.showSelectedMovie(movie);
            return movie;
        }
    }

    throw NotFoundException("Movie not found");
}

SessionDTO ReservationController::selectSession(const MovieDTO& movie) {
    std::vector<SessionDTO> sessions = reservationService.getSessionsByMovie(movie.id);
    reservationView.showSessions(sessions);

    int sessionId = reservationView.askSessionId();

    for (const SessionDTO& session : sessions) {
        if (session.id == sessionId) {
            reservationView.showSelectedSession(session);
            return session;
        }
    }

    throw InvalidDataException("This session does not belong to the selected movie");
}

int ReservationController::selectTicketQuantity() const {
    int quantity = reservationView.askTicketQuantity();
    if (quantity < 1 || quantity > 8) {
        throw InvalidDataException("Ticket quantity must be between 1 and 8");
    }
    return quantity;
}

std::string ReservationController::formatSeatCode(const std::string& seatCode) const {
    std::string formatted;
    for (char character : seatCode) {
        if (!std::isspace(static_cast<unsigned char>(character))) {
            formatted += static_cast<char>(std::toupper(static_cast<unsigned char>(character)));
        }
    }
    return formatted;
}

std::vector<std::string> ReservationController::selectSeats(int sessionId, int ticketQuantity) const {
    std::vector<std::string> selectedSeats;

    while (static_cast<int>(selectedSeats.size()) < ticketQuantity) {
        reservationView.showSeats(reservationService.getSeatsBySession(sessionId), selectedSeats);
        reservationView.showSelectedSeats(selectedSeats);

        std::string seatCode = formatSeatCode(
            reservationView.askSeatCode(static_cast<int>(selectedSeats.size()) + 1)
        );

        if (reservationService.isSeatAvailable(sessionId, seatCode, selectedSeats)) {
            selectedSeats.push_back(seatCode);
            reservationView.showSeatSelected(seatCode);
        } else {
            reservationView.showSeatUnavailable();
        }
    }

    reservationView.showSeats(reservationService.getSeatsBySession(sessionId), selectedSeats);
    return selectedSeats;
}

void ReservationController::makeReservation(int userId) {
    reservationView.showReservationHeader();

    MovieDTO movie = selectMovie();
    SessionDTO session = selectSession(movie);
    int ticketQuantity = selectTicketQuantity();
    std::vector<std::string> selectedSeats = selectSeats(session.id, ticketQuantity);

    int ticketOption = reservationView.askTicketType(session.basePrice);
    double amount = reservationService.calculateAmount(session.id, ticketOption, ticketQuantity);

    int paymentOption = reservationView.askPaymentMethod(amount);
    reservationView.showPaymentApproved();

    ReservationDTO reservation = reservationService.createReservation(
        userId,
        movie.id,
        session.id,
        ticketOption,
        paymentOption,
        selectedSeats
    );

    reservationView.showReservationSuccess(reservation);
}

void ReservationController::viewMyReservations(int userId) const {
    reservationView.showMyReservationsHeader();
    reservationView.showReservations(reservationService.getReservationsByUser(userId));
}