#ifndef RESERVATIONDTO_H
#define RESERVATIONDTO_H

#include <string>
#include <vector>

class ReservationDTO {
public:
    int id;
    std::string userName;
    std::string movieTitle;
    std::string sessionTime;
    std::string room;
    std::string ticketType;
    std::string paymentMethod;
    double amount;
    std::vector<std::string> seats;

    ReservationDTO() : id(0), amount(0.0) {}
};

#endif
