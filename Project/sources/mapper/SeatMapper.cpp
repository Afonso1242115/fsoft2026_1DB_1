#include "SeatMapper.h"

SeatDTO SeatMapper::modelToDTO(const Seat& seat) {
    return SeatDTO(seat.getCode(), seat.isReserved());
}

std::vector<SeatDTO> SeatMapper::listToDTO(const std::vector<Seat>& seats) {
    std::vector<SeatDTO> dtos;
    for (const Seat& seat : seats) dtos.push_back(modelToDTO(seat));
    return dtos;
}
