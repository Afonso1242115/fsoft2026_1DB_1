#ifndef RESERVATIONSERVICE_H
#define RESERVATIONSERVICE_H

#include "IMovieTicketRepository.h"
#include "MovieDTO.h"
#include "SessionDTO.h"
#include "SeatDTO.h"
#include "ReservationDTO.h"
#include "Ticket.h"
#include "Payment.h"
#include <vector>
#include <string>

class ReservationService {
private:
    IMovieTicketRepository& repository;

    User* getUserById(int userId);
    Movie* getMovieById(int movieId);
    Session* getSessionById(int sessionId);

    Ticket createTicketFromOption(int ticketOption);
    Payment createPaymentFromOption(int paymentOption, double amount);

public:
    ReservationService(IMovieTicketRepository& repository);

    std::vector<MovieDTO> getMovies() const;
    std::vector<SessionDTO> getSessionsByMovie(int movieId) const;
    std::vector<SeatDTO> getSeatsBySession(int sessionId) const;

    bool isSeatAvailable(int sessionId,
                         const std::string& seatCode,
                         const std::vector<std::string>& selectedSeats) const;

    double calculateAmount(int sessionId, int ticketOption, int ticketQuantity);

    ReservationDTO createReservation(int userId,
                                     int movieId,
                                     int sessionId,
                                     int ticketOption,
                                     int paymentOption,
                                     const std::vector<std::string>& seats);

    std::vector<ReservationDTO> getReservationsByUser(int userId) const;
};

#endif
