//
// Created by Afonso on 13/05/2026.
//

#ifndef MOVIETICKETSYSTEM_TICKET_H
#define MOVIETICKETSYSTEM_TICKET_H
#include "Seat.h"
#include <string>

class Ticket {
private:
    int id;
    Seat* seat;
    double price;
    SeatType seatType;

public:
    Ticket(int id, Seat* seat, double price);

    int getId() const;
    Seat* getSeat() const;
    double getPrice() const;
    SeatType getSeatType() const;

    std::string toString() const;
};
#endif //MOVIETICKETSYSTEM_TICKET_H
