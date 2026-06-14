#include "Ticket.h"

Ticket::Ticket() : type("Normal"), discount(1.0) {}
Ticket::Ticket(const std::string& type, double discount) : type(type), discount(discount) {}

const std::string& Ticket::getType() const {
    return type;
}
double Ticket::getDiscount() const {
    return discount;
}
double Ticket::calculatePrice(double basePrice) const {
    return basePrice * discount;
}
