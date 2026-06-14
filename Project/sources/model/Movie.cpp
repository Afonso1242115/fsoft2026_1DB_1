
#include "Movie.h"

Movie::Movie(int id, const std::string& title, int durationMinutes, const std::string& genre) {
    this->id = id;
    this->title = title;
    this->durationMinutes = durationMinutes;
    this->genre = genre;
}

int Movie::getId() const {
    return id;
}
const std::string& Movie::getTitle() const {
    return title;
}
int Movie::getDurationMinutes() const {
    return durationMinutes;
}
const std::string& Movie::getGenre() const {
    return genre;
}
bool Movie::operator==(int id) const {
    return this->id == id;
}
