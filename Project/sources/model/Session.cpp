//
// Created by Afonso on 13/05/2026.
//
#include "../../headers/model/Session.h"
#include <iostream>
#include <sstream>

Session::Session(int id, Movie* movie, const std::string& dateTime,
                 double regularPrice, double vipPrice,
                 int totalRows, int seatsPerRow, int vipRows)
    : id(id), movie(movie), dateTime(dateTime),
      regularPrice(regularPrice), vipPrice(vipPrice) {
    initSeats(totalRows, seatsPerRow, vipRows);
}

void Session::initSeats(int totalRows, int seatsPerRow, int vipRows) {
    seats.clear();
    for (int r = 0; r < totalRows; r++) {
        std::string row(1, static_cast<char>('A' + r));
        SeatType type = (r < vipRows) ? SeatType::VIP : SeatType::REGULAR;
        for (int n = 1; n <= seatsPerRow; n++)
            seats.emplace_back(n, row, type);
    }
}

int Session::getId() const { return id; }
Movie* Session::getMovie() const { return movie; }
std::string Session::getDateTime() const { return dateTime; }
double Session::getRegularPrice() const { return regularPrice; }
double Session::getVipPrice() const { return vipPrice; }

double Session::getPrice(SeatType type) const {
    return (type == SeatType::VIP) ? vipPrice : regularPrice;
}

int Session::getAvailableSeats() const {
    int count = 0;
    for (const auto& s : seats)
        if (!s.isReserved()) count++;
    return count;
}

Seat* Session::getSeat(const std::string& row, int number) {
    for (auto& s : seats)
        if (s.getRow() == row && s.getNumber() == number)
            return &s;
    return nullptr;
}

const std::vector<Seat>& Session::getSeats() const { return seats; }

bool Session::reserveSeat(const std::string& row, int number) {
    Seat* s = getSeat(row, number);
    return s ? s->reserve() : false;
}

bool Session::releaseSeat(const std::string& row, int number) {
    Seat* s = getSeat(row, number);
    if (!s) return false;
    s->release();
    return true;
}

void Session::showSeatMap() const {
    std::cout << "\n=== Seat Map - " << movie->getTitle()
              << " | " << dateTime << " ===\n";
    std::cout << "  [X] Occupied  [ ] Available  (V=VIP  R=Regular)\n\n";
    std::string currentRow = "";
    for (const auto& s : seats) {
        if (s.getRow() != currentRow) {
            if (!currentRow.empty()) std::cout << "\n";
            currentRow = s.getRow();
            std::cout << currentRow << " ";
        }
        std::string label = (s.getType() == SeatType::VIP) ? "V" : "R";
        std::cout << (s.isReserved() ? "[X]" : "[" + label + "]") << " ";
    }
    std::cout << "\n\n";
}

std::string Session::toString() const {
    std::ostringstream oss;
    oss << "[" << id << "] " << movie->getTitle()
        << " | " << dateTime
        << " | Available: " << getAvailableSeats()
        << " | Regular: " << regularPrice << " EUR"
        << " | VIP: " << vipPrice << " EUR";
    return oss.str();
}