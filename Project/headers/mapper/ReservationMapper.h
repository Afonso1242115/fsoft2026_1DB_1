#ifndef RESERVATIONMAPPER_H
#define RESERVATIONMAPPER_H

#include "Reservation.h"
#include "ReservationDTO.h"
#include <vector>

class ReservationMapper {
public:
    static ReservationDTO modelToDTO(const Reservation* reservation);
    static std::vector<ReservationDTO> listToDTO(const std::vector<Reservation*>& reservations, int userId);
};

#endif
