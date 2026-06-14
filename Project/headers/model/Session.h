#ifndef SESSION_H
#define SESSION_H

#include <string>
#include <vector>
#include "Seat.h"

class Session {
private:
    int id;
    int movieId;
    std::string room;
    std::string time;
    double basePrice;
    std::vector<Seat> seats;

    void createSeats();

public:
    Session(int id, int movieId, const std::string& room, const std::string& time, double basePrice);

    int getId() const;
    int getMovieId() const;
    const std::string& getRoom() const;
    const std::string& getTime() const;
    double getBasePrice() const;
    const std::vector<Seat>& getSeats() const;

    bool isSeatAvailable(const std::string& seatCode, const std::vector<std::string>& selectedSeats) const;
    void reserveSeats(const std::vector<std::string>& selectedSeats);

    bool operator==(int id) const;
};

#endif