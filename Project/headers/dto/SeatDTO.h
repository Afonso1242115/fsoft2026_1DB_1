#ifndef SEATDTO_H
#define SEATDTO_H

#include <string>

class SeatDTO {
public:
    std::string code;
    bool reserved;

    SeatDTO() : reserved(false) {

    }
    SeatDTO(const std::string& code, bool reserved)
        : code(code), reserved(reserved) {

    }
};

#endif