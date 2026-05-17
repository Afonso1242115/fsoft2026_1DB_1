//
// Created by kikok on 15/05/2026.
//

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
#include <string>

class SeatNotAvailableException : public std::runtime_error {
public:
    explicit SeatNotAvailableException(const std::string& seat)
        : std::runtime_error("Seat " + seat + " is not available.") {}
};

class SeatNotFoundException : public std::runtime_error {
public:
    explicit SeatNotFoundException(const std::string& seat)
        : std::runtime_error("Seat " + seat + " does not exist.") {}
};

class PaymentFailedException : public std::runtime_error {
public:
    explicit PaymentFailedException(const std::string& reason)
        : std::runtime_error("Payment failed: " + reason) {}
};

class UserNotFoundException : public std::runtime_error {
public:
    explicit UserNotFoundException(const std::string& username)
        : std::runtime_error("User '" + username + "' not found.") {}
};

class AccountLockedException : public std::runtime_error {
public:
    explicit AccountLockedException(const std::string& username)
        : std::runtime_error("Account '" + username + "' is locked.") {}
};

class InvalidCredentialsException : public std::runtime_error {
public:
    InvalidCredentialsException()
        : std::runtime_error("Invalid username or password.") {}
};

class MovieNotFoundException : public std::runtime_error {
public:
    explicit MovieNotFoundException(int id)
        : std::runtime_error("Movie [" + std::to_string(id) + "] not found.") {}
};

class SessionNotFoundException : public std::runtime_error {
public:
    explicit SessionNotFoundException(int id)
        : std::runtime_error("Session [" + std::to_string(id) + "] not found.") {}
};
#endif //EXCEPTIONS_H
