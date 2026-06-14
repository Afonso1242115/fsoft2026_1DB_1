#ifndef MOVIEDTO_H
#define MOVIEDTO_H

#include <string>

class MovieDTO {
public:
    int id;
    std::string title;
    int durationMinutes;
    std::string genre;

    MovieDTO() : id(0), durationMinutes(0) {}
    MovieDTO(int id, const std::string& title, int durationMinutes, const std::string& genre)
        : id(id), title(title), durationMinutes(durationMinutes), genre(genre) {}
};

#endif