#include "../../headers/model/User.h"
#include <sstream>
#include <cctype>

User::User(int id, const std::string& username,
           const std::string& email, const std::string& password)
    : id(id), username(username), email(email),
      password(password), failedAttempts(0), locked(false) {}

int User::getId() const { return id; }
std::string User::getUsername() const { return username; }
std::string User::getEmail() const { return email; }
bool User::isLocked() const { return locked; }

bool User::checkPassword(const std::string& pw) {
    return password == pw;
}

void User::registerFailedAttempt() {
    failedAttempts++;
    if (failedAttempts >= 3) locked = true;
}

void User::resetAttempts() {
    failedAttempts = 0;
    locked = false;
}

bool User::validatePassword(const std::string& pw) {
    if (pw.size() < 8) return false;
    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (char c : pw) {
        if (std::isupper(c)) hasUpper = true;
        if (std::islower(c)) hasLower = true;
        if (std::isdigit(c)) hasDigit = true;
    }
    return hasUpper && hasLower && hasDigit;
}

bool User::validateEmail(const std::string& email) {
    auto at = email.find('@');
    if (at == std::string::npos || at == 0) return false;
    auto dot = email.find('.', at);
    return dot != std::string::npos && dot < email.size() - 1;
}

std::string User::toString() const {
    std::ostringstream oss;
    oss << "[" << id << "] " << username << " <" << email << ">";
    return oss.str();
}


