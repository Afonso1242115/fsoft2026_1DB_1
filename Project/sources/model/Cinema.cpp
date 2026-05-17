
//
// Created by Afonso on 13/05/2026.
//
#include "../../headers/model/Cinema.h"
#include <iostream>
#include <algorithm>
#include <string>


Cinema::Cinema(const std::string& name, int totalRows, int seatsPerRow, int vipRows)
    : name(name), totalRows(totalRows), seatsPerRow(seatsPerRow), vipRows(vipRows) {}

std::string Cinema::getName() const { return name; }

void Cinema::addMovie(const Movie& movie) { movies.push_back(movie); }
void Cinema::addSession(const Session& session) { sessions.push_back(session); }

const std::vector<Movie>& Cinema::getMovies() const { return movies; }
const std::vector<Session>& Cinema::getSessions() const { return sessions; }

Movie* Cinema::findMovieById(int id) {
    for (auto& m : movies)
        if (m.getId() == id) return &m;
    return nullptr;
}

Session* Cinema::findSessionById(int id) {
    for (auto& s : sessions)
        if (s.getId() == id) return &s;
    return nullptr;
}

int Cinema::getAvailableSeats(int sessionId) const {
    for (const auto& s : sessions)
        if (s.getId() == sessionId) return s.getAvailableSeats();
    return 0;
}

void Cinema::listMovies() const {
    std::cout << "\n=== Movies ===\n";
    if (movies.empty()) { std::cout << "No movies available.\n"; return; }
    for (const auto& m : movies)
        std::cout << m.toString() << "\n";
}

void Cinema::listSessions() const {
    std::cout << "\n=== Sessions ===\n";
    if (sessions.empty()) { std::cout << "No sessions scheduled.\n"; return; }
    for (const auto& s : sessions)
        std::cout << s.toString() << "\n";
}