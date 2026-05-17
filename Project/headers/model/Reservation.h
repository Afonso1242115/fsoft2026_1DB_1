//
// Created by Afonso on 13/05/2026.
//

#ifndef MOVIETICKETSYSTEM_RESERVATION_H
#define MOVIETICKETSYSTEM_RESERVATION_H
#include "Session.h"
#include "Ticket.h"
#include "Payment.h"
#include <vector>
#include <string>
#include "Seat.h"
enum ReservationStatus{ PENDING, CONFIRMED, CANCELLED };

class Reservation {
     private:
        int id;
        int userId;
        Session* session;
        std::string reservationDate;
        std::string bookingReference;
    ReservationStatus status;
    Payment* payment;
    double totalPrice;
    std::vector<Ticket> tickets;

    static std::string generateReference(int id);

public:
    Reservation(int id, int userId, Session* session,
                const std::string& reservationDate);
    ~Reservation();

    int getId() const;
    int getUserId() const;
    std::string getBookingReference() const;
    ReservationStatus getStatus() const;
    double getTotalPrice() const;
    Session* getSession() const;
    const std::vector<Ticket>& getTickets() const;
    Payment* getPayment() const;

    void addTicket(Seat* seat);
    void calculateTotal();

    bool confirm(const std::string& cardNumber,
                 const std::string& expiry,
                 const std::string& cvv);
    void cancel();

    std::string toString() const;
};
#endif //MOVIETICKETSYSTEM_RESERVATION_H
