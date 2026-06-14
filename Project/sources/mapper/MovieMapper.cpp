#include "MovieMapper.h"

MovieDTO MovieMapper::modelToDTO(const Movie& movie) {
    return MovieDTO(movie.getId(), movie.getTitle(), movie.getDurationMinutes(), movie.getGenre());
}

std::vector<MovieDTO> MovieMapper::listToDTO(const std::vector<Movie>& movies) {
    std::vector<MovieDTO> dtos;
    for (const Movie& movie : movies) dtos.push_back(modelToDTO(movie));
    return dtos;
}
