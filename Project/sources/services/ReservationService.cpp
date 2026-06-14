#include "AuthService.h"
#include "UserMapper.h"
#include "Exceptions.h"

AuthService::AuthService(IMovieTicketRepository& repository)
    : repository(repository) {
}

User* AuthService::searchByEmail(const std::string& email) {
    std::vector<User*>& users = repository.getUsers();

    for (User* user : users) {
        if (*user == email) return user;
    }

    return nullptr;
}

UserDTO AuthService::registerUser(const std::string& name,
                                  const std::string& email,
                                  const std::string& password) {
    if (searchByEmail(email) != nullptr) {
        throw DuplicatedDataException("Email already registered");
    }

    User* user = new User(repository.getNextUserId(), name, email, password);
    repository.getUsers().push_back(user);

    return UserMapper::modelToDTO(user);
}

UserDTO AuthService::login(const std::string& email,
                           const std::string& password) {
    User* user = searchByEmail(email);

    if (user == nullptr) {
        throw NotFoundException("User not found");
    }

    if (!user->checkPassword(password)) {
        throw InvalidDataException("Invalid password");
    }

    return UserMapper::modelToDTO(user);
}
