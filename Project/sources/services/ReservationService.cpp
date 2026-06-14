#include "ReservationService.h"
#include "MovieMapper.h"
#include "SessionMapper.h"
#include "SeatMapper.h"
#include "ReservationMapper.h"
#include "Exceptions.h"

ReservationService::ReservationService(IMovieTicketRepository& repository)
    : repository(repository) {
}

User* ReservationService::getUserById(int userId) {
    for (User* user : repository.getUsers()) {
        if (*user == userId) return user;
    }
    throw NotFoundException("User not found");
}

Movie* ReservationService::getMovieById(int movieId) {
    for (Movie& movie : repository.getMovies()) {
        if (movie == movieId) return &movie;
    }
    throw NotFoundException("Movie not found");
}

Session* ReservationService::getSessionById(int sessionId) {
    for (Session& session : repository.getSessions()) {
        if (session == sessionId) return &session;
    }
    throw NotFoundException("Session not found");
}

Ticket ReservationService::createTicketFromOption(int ticketOption) {
    switch (ticketOption) {
        case 1: return Ticket("Normal", 1.00);
        case 2: return Ticket("Student", 0.80);
        case 3: return Ticket("Senior", 0.70);
        default: throw InvalidDataException("Ticket option");
    }
}

Payment ReservationService::createPaymentFromOption(int paymentOption, double amount) {
    switch (paymentOption) {
        case 1: return Payment("Card", amount);
        case 2: return Payment("MBWay", amount);
        case 3: return Payment("Cash", amount);
        default: throw InvalidDataException("Payment option");
    }
}

std::vector<MovieDTO> ReservationService::getMovies() const {
    return MovieMapper::listToDTO(repository.getMovies());
}

std::vector<SessionDTO> ReservationService::getSessionsByMovie(int movieId) const {
    std::vector<Session> movieSessions;

    for (const Session& session : repository.getSessions()) {
        if (session.getMovieId() == movieId) movieSessions.push_back(session);
    }

    if (movieSessions.empty()) throw NotFoundException("No sessions found for this movie");

    return SessionMapper::listToDTO(movieSessions);
}

std::vector<SeatDTO> ReservationService::getSeatsBySession(int sessionId) const {
    for (const Session& session : repository.getSessions()) {
        if (session == sessionId) return SeatMapper::listToDTO(session.getSeats());
    }
    throw NotFoundException("Session not found");
}

bool ReservationService::isSeatAvailable(int sessionId,
                                         const std::string& seatCode,
                                         const std::vector<std::string>& selectedSeats) const {
    for (const Session& session : repository.getSessions()) {
        if (session == sessionId) return session.isSeatAvailable(seatCode, selectedSeats);
    }
    throw NotFoundException("Session not found");
}

double ReservationService::calculateAmount(int sessionId, int ticketOption, int ticketQuantity) {
    if (ticketQuantity < 1 || ticketQuantity > 8) {
        throw InvalidDataException("Ticket quantity must be between 1 and 8");
    }

    Session* session = getSessionById(sessionId);
    Ticket ticket = createTicketFromOption(ticketOption);
    return ticket.calculatePrice(session->getBasePrice()) * ticketQuantity;
}

ReservationDTO ReservationService::createReservation(int userId,
                                                     int movieId,
                                                     int sessionId,
                                                     int ticketOption,
                                                     int paymentOption,
                                                     const std::vector<std::string>& seats) {
    if (seats.empty()) throw InvalidDataException("At least one seat must be selected");

    User* user = getUserById(userId);
    Movie* movie = getMovieById(movieId);
    Session* session = getSessionById(sessionId);

    if (session->getMovieId() != movie->getId()) {
        throw InvalidDataException("This session does not belong to the selected movie");
    }

    Ticket ticket = createTicketFromOption(ticketOption);
    double amount = ticket.calculatePrice(session->getBasePrice()) * seats.size();
    Payment payment = createPaymentFromOption(paymentOption, amount);

    session->reserveSeats(seats);

    Reservation* reservation = new Reservation(
        repository.getNextReservationId(),
        user,
        movie,
        session,
        ticket,
        payment,
        seats
    );

    repository.getReservations().push_back(reservation);

    return ReservationMapper::modelToDTO(reservation);
}

std::vector<ReservationDTO> ReservationService::getReservationsByUser(int userId) const {
    return ReservationMapper::listToDTO(repository.getReservations(), userId);
}
