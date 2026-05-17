//
// Created by Afonso on 13/05/2026.
//

#ifndef MOVIETICKETSYSTEM_MOVIE_H
#define MOVIETICKETSYSTEM_MOVIE_H
#include <string>

class Movie {
private:
    int id;
    std::string title;
    std::string genre;
    int durationMin;
    std::string rating;
    std::string synopsis;

public:
    Movie(int id, const std::string& title, const std::string& genre,
          int durationMin, const std::string& rating, const std::string& synopsis);

    int getId() const;
    std::string getTitle() const;
    std::string getGenre() const;
    int getDurationMin() const;
    std::string getRating() const;
    std::string getSynopsis() const;

    void setTitle(const std::string& title);
    void setGenre(const std::string& genre);
    void setDurationMin(int durationMin);
    void setRating(const std::string& rating);
    void setSynopsis(const std::string& synopsis);

    std::string toString() const;
};
#endif //MOVIETICKETSYSTEM_MOVIE_H
