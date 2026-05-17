//
// Created by Afonso on 13/05/2026.
//

#ifndef MOVIETICKETSYSTEM_SESSION_H
#define MOVIETICKETSYSTEM_SESSION_H
#include "Movie.h"
#include "Seat.h"
#include <vector>
#include <string>

class Session {
private:
    int id;
    Movie* movie;
    std::string dateTime;
    double regularPrice;
    double vipPrice;
    std::vector<Seat> seats;

    void initSeats(int totalRows, int seatsPerRow, int vipRows);

public:
    Session(int id, Movie* movie, const std::string& dateTime,
            double regularPrice, double vipPrice,
            int totalRows, int seatsPerRow, int vipRows);

    int getId() const;
    Movie* getMovie() const;
    std::string getDateTime() const;
    double getRegularPrice() const;
    double getVipPrice() const;
    double getPrice(SeatType type) const;
    int getAvailableSeats() const;

    Seat* getSeat(const std::string& row, int number);
    const std::vector<Seat>& getSeats() const;

    bool reserveSeat(const std::string& row, int number);
    bool releaseSeat(const std::string& row, int number);

    void showSeatMap() const;
    std::string toString() const;
};
#endif //MOVIETICKETSYSTEM_SESSION_H
