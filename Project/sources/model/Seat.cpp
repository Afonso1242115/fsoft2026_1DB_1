#include "Seat.h"

Seat::Seat(const std::string& code) {
    this->code = code;
    this->reserved = false;
}

const std::string& Seat::getCode() const { return code; }
bool Seat::isReserved() const { return reserved; }
void Seat::reserve() { reserved = true; }
bool Seat::operator==(const std::string& code) const { return this->code == code; }
