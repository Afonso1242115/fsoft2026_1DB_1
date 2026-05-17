//
// Created by Afonso on 13/05/2026.
//
#include "../../headers/model/Reservation.h"
#include <sstream>
#include <iomanip>

Reservation::Reservation(int id, int userId, Session* session,
                           const std::string& reservationDate)
    : id(id), userId(userId), session(session),
      reservationDate(reservationDate),
      bookingReference(generateReference(id)),
      status(ReservationStatus::PENDING),
      payment(nullptr), totalPrice(0.0) {
}

Reservation::~Reservation() {
    delete payment;
}

std::string Reservation::generateReference(int id) {
    std::ostringstream oss;
    oss << "CIN-" << std::setw(5) << std::setfill('0') << id;
    return oss.str();
}

int Reservation::getId() const { return id; }
int Reservation::getUserId() const { return userId; }
std::string Reservation::getBookingReference() const { return bookingReference; }
ReservationStatus Reservation::getStatus() const { return status; }
double Reservation::getTotalPrice() const { return totalPrice; }
Session* Reservation::getSession() const { return session; }
const std::vector<Ticket>& Reservation::getTickets() const { return tickets; }
Payment* Reservation::getPayment() const { return payment; }

void Reservation::addTicket(Seat* seat) {
    int ticketId = static_cast<int>(tickets.size()) + 1;
    double price = session->getPrice(seat->getType());
    tickets.emplace_back(ticketId, seat, price);
    calculateTotal();
}

void Reservation::calculateTotal() {
    totalPrice = 0.0;
    for (const auto& t : tickets)
        totalPrice += t.getPrice();
}

bool Reservation::confirm(const std::string& cardNumber,
                            const std::string& expiry,
                            const std::string& cvv) {
    if (status != ReservationStatus::PENDING) return false;

    payment = new Payment(id, totalPrice, "Credit Card");
    if (!payment->process(cardNumber, expiry, cvv))
        return false;

    for (auto& t : tickets)
        t.getSeat()->reserve();

    status = ReservationStatus::CONFIRMED;
    return true;
}

void Reservation::cancel() {
    if (status == ReservationStatus::CONFIRMED) {
        for (auto& t : tickets)
            t.getSeat()->release();
    }
    status = ReservationStatus::CANCELLED;
}

std::string Reservation::toString() const {
    std::ostringstream oss;
    oss << "=== Booking Confirmation ===\n";
    oss << "Reference:  " << bookingReference << "\n";
    oss << "Movie:      " << session->getMovie()->getTitle() << "\n";
    oss << "Session:    " << session->getDateTime() << "\n";
    oss << "Tickets:\n";
    for (const auto& t : tickets)
        oss << "  " << t.toString() << "\n";
    oss << "Total:      " << std::fixed << std::setprecision(2) << totalPrice << " EUR\n";
    std::string statusStr;
    switch (status) {
        case ReservationStatus::CONFIRMED:  statusStr = "Confirmed";  break;
        case ReservationStatus::CANCELLED:  statusStr = "Cancelled";  break;
        default:                             statusStr = "Pending";    break;
    }
    oss << "Status:     " << statusStr << "\n";
    return oss.str();
}