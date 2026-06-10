#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    int id;
    std::string title;
    int durationMinutes;
    std::string genre;

public:
    Movie(int id,
          const std::string& title,
          int durationMinutes,
          const std::string& genre);

    int getId() const;
    const std::string& getTitle() const;
    int getDurationMinutes() const;
    const std::string& getGenre() const;

    bool operator==(int id) const;
};

#endif