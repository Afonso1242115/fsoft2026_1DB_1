//
// Created by kikok on 15/03/2026.
//

#include "../../headers/model/Seat.h"
#include <sstream>

Seat::Seat(int number, const std::string& row, SeatType type)
    : number(number), row(row), type(type), reserved(false) {}

int Seat::getNumber() const { return number; }
std::string Seat::getRow() const { return row; }
SeatType Seat::getType() const { return type; }
bool Seat::isReserved() const { return reserved; }
x
bool Seat::reserve() {
    if (reserved) return false;
    reserved = true;
    return true;
}

void Seat::release() {
    reserved = false;
}

std::string Seat::toString() const {
    std::ostringstream oss;
    std::string typeStr = (type == SeatType::VIP) ? "VIP" : "Regular";
    std::string statusStr = reserved ? "[X]" : "[ ]";
    oss << statusStr << " " << row << number << " (" << typeStr << ")";
    return oss.str();
}