#ifndef SESSIONDTO_H
#define SESSIONDTO_H

#include <string>

class SessionDTO {
public:
    int id;
    int movieId;
    std::string room;
    std::string time;
    double basePrice;

    SessionDTO() : id(0), movieId(0), basePrice(0.0) {}
    SessionDTO(int id, int movieId, const std::string& room, const std::string& time, double basePrice)
        : id(id), movieId(movieId), room(room), time(time), basePrice(basePrice) {}
};

#endif