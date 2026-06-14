#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include "IMovieTicketRepository.h"
#include "UserDTO.h"
#include <string>

class AuthService {
private:
    IMovieTicketRepository& repository;

    User* searchByEmail(const std::string& email);

public:
    AuthService(IMovieTicketRepository& repository);

    UserDTO registerUser(const std::string& name,
                         const std::string& email,
                         const std::string& password);

    UserDTO login(const std::string& email,
                  const std::string& password);
};

#endif
