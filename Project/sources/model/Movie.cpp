// Created by Afonso on 13/05/2026.
//
#include "../../headers/model/Movie.h"
#include <sstream>

Movie::Movie(int id, const std::string& title, const std::string& genre,
             int durationMin, const std::string& rating, const std::string& synopsis)
    : id(id), title(title), genre(genre),
      durationMin(durationMin), rating(rating), synopsis(synopsis) {}

int Movie::getId() const { return id; }
std::string Movie::getTitle() const { return title; }
std::string Movie::getGenre() const { return genre; }
int Movie::getDurationMin() const { return durationMin; }
std::string Movie::getRating() const { return rating; }
std::string Movie::getSynopsis() const { return synopsis; }

void Movie::setTitle(const std::string& title) { this->title = title; }
void Movie::setGenre(const std::string& genre) { this->genre = genre; }
void Movie::setDurationMin(int durationMin) { this->durationMin = durationMin; }
void Movie::setRating(const std::string& rating) { this->rating = rating; }
void Movie::setSynopsis(const std::string& synopsis) { this->synopsis = synopsis; }

std::string Movie::toString() const {
    std::ostringstream oss;
    oss << "[" << id << "] " << title
        << " | " << genre
        << " | " << durationMin << " min"
        << " | " << rating;
    return oss.str();
}