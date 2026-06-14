#ifndef MOVIETICKETREPOSITORYMEMORY_H
#define MOVIETICKETREPOSITORYMEMORY_H

#include "IMovieTicketRepository.h"

class MovieTicketRepositoryMemory : public IMovieTicketRepository {
private:
    std::vector<User*> users;
    std::vector<Movie> movies;
    std::vector<Session> sessions;
    std::vector<Reservation*> reservations;
    int nextUserId;
    int nextReservationId;

public:
    MovieTicketRepositoryMemory();
    ~MovieTicketRepositoryMemory();

    std::vector<User*>& getUsers();
    std::vector<Movie>& getMovies();
    std::vector<Session>& getSessions();
    std::vector<Reservation*>& getReservations();

    int getNextUserId();
    int getNextReservationId();
};

#endif
