#include "Session.h"

Session::Session(int id,
                 int movieId,
                 const std::string& room,
                 const std::string& time,
                 double basePrice) {
    this->id = id;
    this->movieId = movieId;
    this->room = room;
    this->time = time;
    this->basePrice = basePrice;
}

int Session::getId() const {
    return id;
}

int Session::getMovieId() const {
    return movieId;
}

const std::string& Session::getRoom() const {
    return room;
}

const std::string& Session::getTime() const {
    return time;
}

double Session::getBasePrice() const {
    return basePrice;
}

bool Session::operator==(int id) const {
    return this->id == id;
}