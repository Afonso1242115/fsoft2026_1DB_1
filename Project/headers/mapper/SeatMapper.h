#ifndef SEATMAPPER_H
#define SEATMAPPER_H

#include "Seat.h"
#include "SeatDTO.h"
#include <vector>

class SeatMapper {
public:
    static SeatDTO modelToDTO(const Seat& seat);
    static std::vector<SeatDTO> listToDTO(const std::vector<Seat>& seats);
};

#endif
