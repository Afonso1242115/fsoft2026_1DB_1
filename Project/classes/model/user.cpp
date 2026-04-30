#include "user.h"

// Default constructor
User::User() : username(""), email(""), password("") {}

// Parameterized constructor
User::User(const std::string& username, const std::string& email, const std::string& password)
    : username(username), email(email), password(password) {}

// Getters
std::string User::getUsername() const {
    return username;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getPassword() const {
    return password;
}

// Setters
void User::setUsername(const std::string& username) {
    this->username = username;
}

void User::setEmail(const std::string& email) {
    this->email = email;
}

void User::setPassword(const std::string& password) {
    this->password = password;
}

// Authenticate: checks if input matches stored password
bool User::authenticate(const std::string& inputPassword) const {
    return password == inputPassword;
}