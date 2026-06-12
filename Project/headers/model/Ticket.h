#ifndef TICKET_H
#define TICKET_H

#include <string>

class Ticket {
private:
    std::string type;
    double discount;

public:
    Ticket();
    Ticket(const std::string& type, double discount);
    const std::string& getType() const;
    double getDiscount() const;
    double calculatePrice(double basePrice) const;
};

#endif
