#ifndef IMOVIETICKETREPOSITORY_H
#define IMOVIETICKETREPOSITORY_H

#include "User.h"
#include "Movie.h"
#include "Session.h"
#include "Reservation.h"
#include <vector>

class IMovieTicketRepository {
public:
    virtual ~IMovieTicketRepository() {

    }

    virtual std::vector<User*>& getUsers() = 0;
    virtual std::vector<Movie>& getMovies() = 0;
    virtual std::vector<Session>& getSessions() = 0;
    virtual std::vector<Reservation*>& getReservations() = 0;

    virtual int getNextUserId() = 0;
    virtual int getNextReservationId() = 0;
};

#endif
