#ifndef RESERVATION_H
#define RESERVATION_H

#include "User.h"
#include "Movie.h"
#include "Session.h"
#include "Ticket.h"
#include "Payment.h"
#include <vector>
#include <string>

class Reservation {
private:
    int id;
    User* user;
    Movie* movie;
    Session* session;
    Ticket ticket;
    Payment payment;
    std::vector<std::string> seats;

public:
    Reservation(int id, User* user, Movie* movie, Session* session,
                const Ticket& ticket, const Payment& payment,
                const std::vector<std::string>& seats);

    int getId() const;
    User* getUser() const;
    Movie* getMovie() const;
    Session* getSession() const;
    const Ticket& getTicket() const;
    const Payment& getPayment() const;
    const std::vector<std::string>& getSeats() const;
};

#endif