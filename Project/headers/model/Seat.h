#ifndef SEAT_H
#define SEAT_H
#include <string>

enum SeatType { REGULAR, VIP };
class Seat {
private:
    int number;
    std::string row;
    SeatType type;
    bool reserved;

public:
    Seat(int number, const std::string& row, SeatType type);

    int getNumber() const;
    std::string getRow() const;
    SeatType getType() const;
    bool isReserved() const;

    bool reserve();
    void release();

    std::string toString() const;
};
#endif