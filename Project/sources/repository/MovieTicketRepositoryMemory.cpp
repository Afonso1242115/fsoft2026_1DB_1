#include "MovieTicketRepositoryMemory.h"

MovieTicketRepositoryMemory::MovieTicketRepositoryMemory() {
    nextUserId = 1;
    nextReservationId = 1;

    movies.push_back(Movie(1, "Interstellar", 169, "Sci-Fi"));
    movies.push_back(Movie(2, "The Notebook", 121, "Drama"));
    movies.push_back(Movie(3, "Project Hail Mary", 156, "Sci-Fi"));

    sessions.push_back(Session(1, 1, "Room 1", "14:30", 7.50));
    sessions.push_back(Session(2, 1, "Room 2", "18:00", 8.00));
    sessions.push_back(Session(3, 2, "Room 1", "16:00", 7.00));
    sessions.push_back(Session(4, 2, "Room 3", "21:30", 8.50));
    sessions.push_back(Session(5, 3, "Room 2", "20:00", 8.00));
}

MovieTicketRepositoryMemory::~MovieTicketRepositoryMemory() {
    for (User* user : users) delete user;
    for (Reservation* reservation : reservations) delete reservation;
}

std::vector<User*>& MovieTicketRepositoryMemory::getUsers() { return users; }
std::vector<Movie>& MovieTicketRepositoryMemory::getMovies() { return movies; }
std::vector<Session>& MovieTicketRepositoryMemory::getSessions() { return sessions; }
std::vector<Reservation*>& MovieTicketRepositoryMemory::getReservations() { return reservations; }

int MovieTicketRepositoryMemory::getNextUserId() { return nextUserId++; }
int MovieTicketRepositoryMemory::getNextReservationId() { return nextReservationId++; }