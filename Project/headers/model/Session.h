#ifndef SESSION_H
#define SESSION_H

#include <string>

class Session {
private:
    int id;
    int movieId;
    std::string room;
    std::string time;
    double basePrice;

public:
    Session(int id,
            int movieId,
            const std::string& room,
            const std::string& time,
            double basePrice);

    int getId() const;
    int getMovieId() const;
    const std::string& getRoom() const;
    const std::string& getTime() const;
    double getBasePrice() const;

    bool operator==(int id) const;
};

#endif