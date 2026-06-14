#ifndef MOVIEMAPPER_H
#define MOVIEMAPPER_H

#include "Movie.h"
#include "MovieDTO.h"
#include <vector>

class MovieMapper {
public:
    static MovieDTO modelToDTO(const Movie& movie);
    static std::vector<MovieDTO> listToDTO(const std::vector<Movie>& movies);
};

#endif
