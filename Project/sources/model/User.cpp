#include "User.h"
#include "Exceptions.h"

User::User(int id, const std::string& name, const std::string& email, const std::string& password) {
    this->id = id;
    setName(name);
    setEmail(email);
    setPassword(password);
}

bool User::isNameValid(const std::string& name) { return name.length() >= 3; }

bool User::isEmailValid(const std::string& email) {
    return email.find('@') != std::string::npos && email.find('.') != std::string::npos;
}

bool User::isPasswordValid(const std::string& password) {
    if (password.length() < 8) return false;

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasNumber = false;

    for (char character : password) {
        if (character >= 'A' && character <= 'Z') hasUppercase = true;
        else if (character >= 'a' && character <= 'z') hasLowercase = true;
        else if (character >= '0' && character <= '9') hasNumber = true;
    }

    return hasUppercase && hasLowercase && hasNumber;
}

int User::getId() const { return id; }
const std::string& User::getName() const { return name; }
const std::string& User::getEmail() const { return email; }

void User::setName(const std::string& name) {
    if (!isNameValid(name)) throw InvalidDataException("Name must have at least 3 characters");
    this->name = name;
}

void User::setEmail(const std::string& email) {
    if (!isEmailValid(email)) throw InvalidDataException("Email must contain @ and .");
    this->email = email;
}

void User::setPassword(const std::string& password) {
    if (!isPasswordValid(password)) {
        throw InvalidDataException("Password must have at least 8 characters, one uppercase letter, one lowercase letter and one number");
    }
    this->password = password;
}

bool User::checkPassword(const std::string& password) const { return this->password == password; }
bool User::operator==(int id) const { return this->id == id; }
bool User::operator==(const std::string& email) const { return this->email == email; }
