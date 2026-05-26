#include "UserContainer.h"
#include "Exceptions.h"

UserContainer::UserContainer() : nextId(1) {
}

User* UserContainer::searchByEmail(const std::string& email) {
    for (User& user : users) {
        if (user == email) {
            return &user;
        }
    }

    return nullptr;
}

void UserContainer::add(const std::string& name,
                        const std::string& email,
                        const std::string& password) {
    if (searchByEmail(email) != nullptr) {
        throw DuplicatedDataException("Email already registered");
    }

    users.push_back(User(nextId, name, email, password));
    nextId++;
}

User* UserContainer::login(const std::string& email,
                           const std::string& password) {
    User* user = searchByEmail(email);

    if (user == nullptr) {
        throw NotFoundException("User not found");
    }

    if (!user->checkPassword(password)) {
        throw InvalidDataException("Wrong password");
    }

    return user;
}
