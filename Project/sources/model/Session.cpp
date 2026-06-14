#include "Session.h"
#include "Exceptions.h"

Session::Session(int id, int movieId, const std::string& room, const std::string& time, double basePrice) {
    this->id = id;
    this->movieId = movieId;
    this->room = room;
    this->time = time;
    this->basePrice = basePrice;

    createSeats();
}

void Session::createSeats() {
    seats.push_back(Seat("A1"));
    seats.push_back(Seat("A2"));
    seats.push_back(Seat("A3"));
    seats.push_back(Seat("A4"));

    seats.push_back(Seat("B1"));
    seats.push_back(Seat("B2"));
    seats.push_back(Seat("B3"));
    seats.push_back(Seat("B4"));

    seats.push_back(Seat("C1"));
    seats.push_back(Seat("C2"));
    seats.push_back(Seat("C3"));
    seats.push_back(Seat("C4"));
    createSeats();
}

void Session::createSeats() {
    seats.push_back(Seat("A1")); seats.push_back(Seat("A2")); seats.push_back(Seat("A3")); seats.push_back(Seat("A4"));
    seats.push_back(Seat("B1")); seats.push_back(Seat("B2")); seats.push_back(Seat("B3")); seats.push_back(Seat("B4"));
    seats.push_back(Seat("C1")); seats.push_back(Seat("C2")); seats.push_back(Seat("C3")); seats.push_back(Seat("C4"));
}

int Session::getId() const { return id; }
int Session::getMovieId() const { return movieId; }
const std::string& Session::getRoom() const { return room; }
const std::string& Session::getTime() const { return time; }
double Session::getBasePrice() const { return basePrice; }
const std::vector<Seat>& Session::getSeats() const { return seats; }

bool Session::isSeatAvailable(const std::string& seatCode, const std::vector<std::string>& selectedSeats) const {
    for (const std::string& selectedSeat : selectedSeats) {
        if (selectedSeat == seatCode) return false;
    }
    for (const Seat& seat : seats) {
        if (seat == seatCode) return !seat.isReserved();
    }
    return false;
}

void Session::reserveSeats(const std::vector<std::string>& selectedSeats) {
    for (const std::string& selectedSeat : selectedSeats) {
        bool found = false;
        for (Seat& seat : seats) {
            if (seat == selectedSeat) {
                if (seat.isReserved()) throw InvalidDataException("Seat already reserved");
                seat.reserve();
                found = true;
            }
        }
        if (!found) throw NotFoundException("Seat not found");
    }
}

const std::vector<Seat>& Session::getSeats() const {
    return seats;
}

bool Session::isSeatAvailable(const std::string& seatCode,
                              const std::vector<std::string>& selectedSeats) const {
    for (const std::string& selectedSeat : selectedSeats) {
        if (selectedSeat == seatCode) {
            return false;
        }
    }

    for (const Seat& seat : seats) {
        if (seat == seatCode) {
            return !seat.isReserved();
        }
    }

    return false;
}

void Session::reserveSeats(const std::vector<std::string>& selectedSeats) {
    for (const std::string& selectedSeat : selectedSeats) {
        bool found = false;

        for (Seat& seat : seats) {
            if (seat == selectedSeat) {
                if (seat.isReserved()) {
                    throw InvalidDataException("Seat already reserved");
                }

                seat.reserve();
                found = true;
            }
        }

        if (!found) {
            throw NotFoundException("Seat not found");
        }
    }
}

bool Session::operator==(int id) const {
    return this->id == id;
}
bool Session::operator==(int id) const { return this->id == id; }
