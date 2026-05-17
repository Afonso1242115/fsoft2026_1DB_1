//
// Created by Afonso on 13/05/2026.
//

#ifndef MOVIETICKETSYSTEM_CINEMA_H
#define MOVIETICKETSYSTEM_CINEMA_H
#include "Movie.h"
#include "Session.h"
#include <vector>
#include <string>

class Cinema {
private:
    std::string name;
    int totalRows;
    int seatsPerRow;
    int vipRows;
    std::vector<Movie> movies;
    std::vector<Session> sessions;

public:
    Cinema(const std::string& name, int totalRows, int seatsPerRow, int vipRows);

    std::string getName() const;

    void addMovie(const Movie& movie);
    void addSession(const Session& session);

    Movie* findMovieById(int id);
    Session* findSessionById(int id);

    std::vector<Movie>& getMovies();
    std::vector<Session>& getSessions();

    int getTotalRows() const;
    int getSeatsPerRow() const;
    int getVipRows() const;
};
#endif //MOVIETICKETSYSTEM_CINEMA_H
