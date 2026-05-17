//
// Created by Afonso on 13/05/2026.
//
#include "../../headers/model/Payment.h"
#include <sstream>
#include <cctype>
#include <algorithm>

Payment::Payment(int id, double amount, const std::string& method)
    : id(id), amount(amount), method(method),
      status(PaymentStatus::PENDING) {}

int Payment::getId() const { return id; }
double Payment::getAmount() const { return amount; }
std::string Payment::getMethod() const { return method; }
PaymentStatus Payment::getStatus() const { return status; }
std::string Payment::getPaymentDate() const { return paymentDate; }

bool Payment::process(const std::string& cardNumber,
                       const std::string& expiry,
                       const std::string& cvv) {
    if (!validateCard(cardNumber, expiry, cvv)) {
        status = PaymentStatus::DECLINED;
        return false;
    }
    maskedCardNumber = "****" + cardNumber.substr(cardNumber.size() - 4);
    status = PaymentStatus::APPROVED;
    paymentDate = "2026-05-14";
    return true;
}

bool Payment::validateCard(const std::string& cardNumber,
                             const std::string& expiry,
                             const std::string& cvv) {
    std::string clean = cardNumber;
    clean.erase(std::remove(clean.begin(), clean.end(), ' '), clean.end());
    if (clean.size() != 16) return false;
    for (char c : clean)
        if (!std::isdigit(c)) return false;

    if (expiry.size() != 5 || expiry[2] != '/') return false;

    if (cvv.size() != 3) return false;
    for (char c : cvv)
        if (!std::isdigit(c)) return false;

    return true;
}

std::string Payment::toString() const {
    std::ostringstream oss;
    std::string statusStr;
    switch (status) {
    case PaymentStatus::APPROVED: statusStr = "Approved"; break;
    case PaymentStatus::DECLINED: statusStr = "Declined"; break;
    default:                       statusStr = "Pending";  break;
    }
    oss << "[Payment #" << id << "] "
        << amount << " EUR | " << method
        << " | " << statusStr;
    return oss.str();
}