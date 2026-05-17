//
// Created by Afonso on 13/05/2026.
//
#include "../../headers/model/Ticket.h"
#include <sstream>

Ticket::Ticket(int id, Seat* seat, double price)
    : id(id), seat(seat), price(price), seatType(seat->getType()) {}

int Ticket::getId() const { return id; }
Seat* Ticket::getSeat() const { return seat; }
double Ticket::getPrice() const { return price; }
SeatType Ticket::getSeatType() const { return seatType; }

std::string Ticket::toString() const {
    std::ostringstream oss;
    std::string typeStr = (seatType == SeatType::VIP) ? "VIP" : "Regular";
    oss << "[Ticket #" << id << "] "
        << "Seat " << seat->getRow() << seat->getNumber()
        << " (" << typeStr << ")"
        << " | " << price << " EUR";
    return oss.str();
}