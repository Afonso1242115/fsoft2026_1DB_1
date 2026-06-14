#ifndef SEAT_H
#define SEAT_H

#include <string>

class Seat {
private:
    std::string code;
    bool reserved;

public:
    Seat(const std::string& code);
    const std::string& getCode() const;
    bool isReserved() const;
    void reserve();
    bool operator==(const std::string& code) const;
};

#endif
