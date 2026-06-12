#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InvalidDataException : public std::runtime_error {
public:
    explicit InvalidDataException(const std::string& message)
    : std::runtime_error(message) {}
};

class DuplicatedDataException : public std::runtime_error {
public:
    explicit DuplicatedDataException(const std::string& message)
    : std::runtime_error(message) {}
};

class NotFoundException : public std::runtime_error {
public:
    explicit NotFoundException(const std::string& message)
    : std::runtime_error(message) {}
};

class DataConsistencyException : public std::runtime_error {
public:
    explicit DataConsistencyException(const std::string& message)
    : std::runtime_error(message) {}
};

#endif
