#ifndef RESERVATIONCONTROLLER_H
#define RESERVATIONCONTROLLER_H

#include "../model/Cinema.h"
#include "../model/User.h"
#include "../model/Session.h"
#include "../model/Ticket.h"
#include "../model/Payment.h"
#include "../view/ReservationView.h"
#include <string>
#include <vector>

class ReservationController {
private:
    Cinema& cinema;
    ReservationView view;

    std::string formatSeatCode(const std::string& seatCode) const;

    int selectTicketQuantity() const;
    std::vector<std::string> selectSeats(Session* session, int ticketQuantity) const;
    Ticket selectTicket(double basePrice) const;
    Payment selectPayment(double amount) const;

public:
    ReservationController(Cinema& cinema);

    void makeReservation(User* loggedUser);
    void showUserReservations(User* loggedUser) const;
};

#endif