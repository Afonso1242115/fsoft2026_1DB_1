#include "../../headers/controller/ReservationController.h"
#include "../../headers/model/Exceptions.h"
#include <cctype>

ReservationController::ReservationController(Cinema& cinema)
    : cinema(cinema) {
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
    int quantity = view.askTicketQuantity();

    if (quantity < 1 || quantity > 8) {
        throw InvalidDataException("Ticket quantity must be between 1 and 8");
    }

    return quantity;
}

std::vector<std::string> ReservationController::selectSeats(Session* session, int ticketQuantity) const {
    std::vector<std::string> selectedSeats;

    while (static_cast<int>(selectedSeats.size()) < ticketQuantity) {
        session->showSeats(selectedSeats);
        view.showSelectedSeats(selectedSeats);

        std::string seatCode = formatSeatCode(
            view.askSeatCode(static_cast<int>(selectedSeats.size()) + 1)
        );

        if (session->isSeatAvailable(seatCode, selectedSeats)) {
            selectedSeats.push_back(seatCode);
            view.showSeatSelected(seatCode);
        } else {
            view.showSeatUnavailable();
        }
    }

    session->showSeats(selectedSeats);

    return selectedSeats;
}

Ticket ReservationController::selectTicket(double basePrice) const {
    int option = view.askTicketType(basePrice);

    switch (option) {
        case 1:
            return Ticket("Normal", 1.00);

        case 2:
            return Ticket("Student", 0.80);

        case 3:
            return Ticket("Senior", 0.70);

        default:
            throw InvalidDataException("Ticket option");
    }
}

Payment ReservationController::selectPayment(double amount) const {
    int option = view.askPaymentMethod(amount);

    std::string method;

    switch (option) {
        case 1:
            method = "Card";
            break;

        case 2:
            method = "MBWay";
            break;

        case 3:
            method = "Cash";
            break;

        default:
            throw InvalidDataException("Payment option");
    }

    view.showPaymentApproved();

    return Payment(method, amount);
}

void ReservationController::makeReservation(User* loggedUser) {
    view.showHeader("New Reservation");

    cinema.listMovies();

    int movieId = view.askMovieId();
    cinema.getMovie(movieId);

    cinema.listSessionsByMovie(movieId);

    int sessionId = view.askSessionId();
    Session* session = cinema.getSession(sessionId);

    if (!session->hasFreeSeats()) {
        throw InvalidDataException("This session is sold out");
    }

    int ticketQuantity = selectTicketQuantity();

    std::vector<std::string> selectedSeats = selectSeats(session, ticketQuantity);

    Ticket ticket = selectTicket(session->getBasePrice());

    double amount = ticket.calculatePrice(session->getBasePrice()) * ticketQuantity;

    Payment payment = selectPayment(amount);

    Reservation* reservation = cinema.addReservation(
        loggedUser,
        session,
        ticket,
        selectedSeats,
        payment
    );

    view.showReservationSuccess(reservation);
}

void ReservationController::showUserReservations(User* loggedUser) const {
    cinema.listReservationsByUser(loggedUser);
}