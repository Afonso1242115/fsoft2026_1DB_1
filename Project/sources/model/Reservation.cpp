#include "Reservation.h"

Reservation::Reservation(int id, User* user, Movie* movie, Session* session,
                         const Ticket& ticket, const Payment& payment,
                         const std::vector<std::string>& seats) {
    this->id = id;
    this->user = user;
    this->movie = movie;
    this->session = session;
    this->ticket = ticket;
    this->payment = payment;
    this->seats = seats;
}

int Reservation::getId() const { return id; }
User* Reservation::getUser() const { return user; }
Movie* Reservation::getMovie() const { return movie; }
Session* Reservation::getSession() const { return session; }
const Ticket& Reservation::getTicket() const { return ticket; }
const Payment& Reservation::getPayment() const { return payment; }
const std::vector<std::string>& Reservation::getSeats() const { return seats; }