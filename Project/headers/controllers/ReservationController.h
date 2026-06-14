#ifndef RESERVATIONCONTROLLER_H
#define RESERVATIONCONTROLLER_H

#include "ReservationService.h"
#include "ReservationView.h"
#include "MovieDTO.h"
#include "SessionDTO.h"
#include "ReservationDTO.h"
#include <vector>
#include <string>

class ReservationController {
private:
    ReservationService& reservationService;
    ReservationView reservationView;

    MovieDTO selectMovie();
    SessionDTO selectSession(const MovieDTO& movie);
    int selectTicketQuantity() const;
    std::vector<std::string> selectSeats(int sessionId, int ticketQuantity) const;
    std::string formatSeatCode(const std::string& seatCode) const;

public:
    ReservationController(ReservationService& reservationService);

    void makeReservation(int userId);
    void viewMyReservations(int userId) const;
};

#endif