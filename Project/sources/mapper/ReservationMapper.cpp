#include "ReservationMapper.h"

ReservationDTO ReservationMapper::modelToDTO(const Reservation* reservation) {
    ReservationDTO dto;
    if (reservation == nullptr) return dto;

    dto.id = reservation->getId();
    dto.userName = reservation->getUser()->getName();
    dto.movieTitle = reservation->getMovie()->getTitle();
    dto.sessionTime = reservation->getSession()->getTime();
    dto.room = reservation->getSession()->getRoom();
    dto.ticketType = reservation->getTicket().getType();
    dto.paymentMethod = reservation->getPayment().getMethod();
    dto.amount = reservation->getPayment().getAmount();
    dto.seats = reservation->getSeats();

    return dto;
}

std::vector<ReservationDTO> ReservationMapper::listToDTO(const std::vector<Reservation*>& reservations, int userId) {
    std::vector<ReservationDTO> dtos;
    for (const Reservation* reservation : reservations) {
        if (reservation->getUser()->getId() == userId) dtos.push_back(modelToDTO(reservation));
    }
    return dtos;
}
